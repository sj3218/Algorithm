#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int N, M;
int grid[101][101];
int is_visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Input()
{
    cin >> N >> M;
    string s;
    for (int i = 1; i <= N; ++i)
    {
        cin >> s;

        for (int j = 1; j <= M; ++j)
        {
            grid[i][j] = s[j-1] - '0';
            is_visited[i][j] = 0;
        }
    }
}

bool InRange(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > M)
    {
        return false;
    }
    return true;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({ 1,1 });
    is_visited[1][1] = 1;

    int x, y;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        int val = is_visited[x][y];
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && is_visited[nx][ny] == 0 && grid[nx][ny] == 1)
            {
                is_visited[nx][ny] = val + 1;
                q.push({ nx, ny });
            }
        }
    }
}
int main()
{
    Input();
    bfs();
    cout << is_visited[N][M];
    return 0;
}