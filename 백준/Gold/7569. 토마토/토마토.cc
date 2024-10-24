#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int N, M, H;
int is_visited[101][101][101];
int grid[101][101][101];
queue<tuple<int, int, int>> q;
int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };

void Input()
{
    cin >> M >> N >> H;
    for (int k = 1; k <= H; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                cin >> grid[k][i][j];
                if (grid[k][i][j] == 1)
                {
                    q.push({ i,j,k });
                    is_visited[k][i][j] = 1;
                }
                else
                    is_visited[k][i][j] = 0;
            }
        }
    }


}
bool InRange(int x, int y, int z)
{
    if (x <= 0 || y <= 0 || z <= 0 || x > N || y > M || z > H)
        return false;
    return true;
}

void BFS()
{
    int x, y, z;

    while (!q.empty())
    {
        x = get<0>(q.front());
        y = get<1>(q.front());
        z = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 6; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (InRange(nx, ny, nz))
            {
                if (grid[nz][nx][ny] >= 0 && is_visited[nz][nx][ny] == 0)
                {
                    is_visited[nz][nx][ny] = is_visited[z][x][y] + 1;

                    q.push({ nx, ny, nz });
                }
            }
        }
    }
}

int Count()
{
    int max = 0;
    int tmp;

    for (int k = 1; k <= H; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= M; ++j)
            {
                tmp = is_visited[k][i][j];

                if (grid[k][i][j] >= 0)
                {
                    if (tmp == 0)
                    {
                        return -1;
                    }

                    if (tmp > max)
                    {
                        max = tmp;
                    }
                }
            }
        }
    }

    return max - 1;
}

int main()
{
    Input();
    BFS();
    cout << Count();

    return 0;
}