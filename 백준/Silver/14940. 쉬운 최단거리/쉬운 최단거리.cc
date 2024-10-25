#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define SIZE 1001

int N, M;
int grid[SIZE][SIZE];
int ans[SIZE][SIZE];
int is_visited[SIZE][SIZE];
pair<int, int> goal_pos;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool InRange(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= M)
        return false;

    return true;
}

void BFS()
{
    queue<pair<int, int>> q;
    q.push(goal_pos);
    is_visited[goal_pos.first][goal_pos.second] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        int val = is_visited[x][y];

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny))
            {
                if (grid[nx][ny] > 0)
                {
                    if (is_visited[nx][ny] == -1)
                    {
                        is_visited[nx][ny] = val + 1;
                        q.push({ nx,ny });
                    }
                }
            }
        }
    }
}

void PrintGrid()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cout << is_visited[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    cin >> N >> M;
    fill_n(grid[0], SIZE * SIZE, 0);
    fill_n(ans[0], SIZE * SIZE, 0);
    fill_n(is_visited[0], SIZE * SIZE, -1);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
            {
                goal_pos = { i,j };
            }
            else if (grid[i][j] == 0)
            {
                is_visited[i][j] = 0;
            }
        }
    }

    BFS();
    PrintGrid();
    return 0;
}