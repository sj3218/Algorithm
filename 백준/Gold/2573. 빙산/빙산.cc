#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, M;
int board[301][301];
bool is_visited[301][301];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0,0 };

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= M)
        return false;
    return true;
}

void MeltGlacier()
{
    int temp_board[301][301];
    fill_n(temp_board[0], 301 * 301, 0);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == 0)
                continue;

            int cnt = 0;
            for (int k = 0; k < 4; ++k)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (!IsValid(nx, ny))
                    continue;
                if (board[nx][ny] == 0)
                    ++cnt;
            }
            
            cnt = board[i][j] - cnt;
            if (cnt > 0)
                temp_board[i][j] = cnt;
        }
    }

    copy_n(temp_board[0], 301 * 301, board[0]);
}

void bfs(int X, int Y)
{
    queue<pair<int, int>> q;
    q.push({ X, Y });
    is_visited[X][Y] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny])
                continue;

            if (board[nx][ny] == 0)
                continue;

            is_visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }

    int time = 0;
    while (true)
    {
        fill_n(is_visited[0], 301 * 301, false);
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (board[i][j] == 0 || is_visited[i][j] != false)
                    continue;
                bfs(i, j);
                ++cnt;
            }
        }

        if (cnt >= 2)
        {
            break;
        }
        else if (cnt <= 0)
        {
            time = 0;
            break;
        }

        ++time;
        MeltGlacier();
    }

    cout << time;
    return 0;
}