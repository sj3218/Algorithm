#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int N, M;
int is_visited[1001][1001];
int grid[1001][1001];
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Input()
{
    cin >> M >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
            {
                q.push({ i,j });
                is_visited[i][j] = 1;
            }
            else
                is_visited[i][j] = 0;
        }
    }
}
bool InRange(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > M)
        return false;
    return true;
}

void BFS()
{
    int x, y;

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny))
            {
                if (grid[nx][ny] >= 0 && is_visited[nx][ny] == 0)
                {
                    is_visited[nx][ny] = is_visited[x][y] + 1;

                    q.push({ nx, ny });
                }
            }
        }
    }
}

int Count()
{
    int max = 0;
    int tmp;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            tmp = is_visited[i][j];
            
            if (grid[i][j] >= 0)
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
    return max - 1;
}

int main()
{
    Input();
    BFS();
    cout << Count();

    return 0;
}