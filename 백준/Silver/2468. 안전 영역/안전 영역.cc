#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N;
int board[101][101];
bool is_visited[101][101];
set<int> height;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > N)
        return false;
    return true;
}

void bfs(int h, int x, int y, bool up)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    is_visited[x][y] = true;

    int cx, cy, nx, ny;
    while (!q.empty())
    {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny])
                continue;

            if (up && board[nx][ny] <= h)
                continue;

            if (!up && board[nx][ny] > h)
                continue;

            is_visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    height.insert(0);

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[i][j];
            height.insert(board[i][j]);
        }
    }

    int answer = 0;

    for (int next : height)
    {
        fill_n(&is_visited[0][0], 101 * 101, false);

        int cnt = 0;
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (is_visited[i][j])
                    continue;

                if (board[i][j] <= next)
                    bfs(next, i, j, false);
                else
                {
                    ++cnt;
                    bfs(next, i, j, true);
                }
            }
        }

        answer = max(answer, cnt);
    }

    cout << answer;
    return 0;
}