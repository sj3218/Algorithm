#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

#define SIZE 101

int N, M, T;
int grid[SIZE][SIZE];
int is_visited[SIZE][SIZE][2];
pair<int, int> sword_pos;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void Input()
{
    fill_n(grid[0], SIZE * SIZE, 0);
    fill_n(is_visited[0][0], SIZE * SIZE * 2, -1);

    cin >> N >> M >> T;

    int val;
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> val;
            if (val == 2)
                sword_pos = { i, j };

            grid[i][j] = val;
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
    queue<tuple<int, int, int>> q;
    q.push({1,1,0});
    int has_sword = 0;
    is_visited[1][1][has_sword] = 0;

    int x, y, val;
    
    while (!q.empty())
    {
        x = get<0>(q.front());
        y = get<1>(q.front());
        has_sword = get<2>(q.front());
        val = is_visited[x][y][has_sword];
        q.pop();

        if (val > T)
            break;

        if (x == N && y == M)
        {
            cout << val;
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny))
            {
                if (is_visited[nx][ny][has_sword] != -1)
                    continue;

                if (has_sword == 0 && grid[nx][ny] == 1)
                    continue;

                if (grid[nx][ny] == 2)
                {
                    is_visited[nx][ny][1] = val + 1;
                    q.push({ nx, ny ,1 });
                    continue;
                }

                is_visited[nx][ny][has_sword] = val + 1;
                q.push({ nx, ny ,has_sword});
            }
        }
    }

    cout << "Fail";
}

int main()
{
    Input();
    BFS();

    return 0;
}