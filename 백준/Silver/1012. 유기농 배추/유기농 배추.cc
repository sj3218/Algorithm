#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int T;
int M, N, K;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0, 0 };

bool map[51][51];
bool is_visited[51][51];
int cnt_worm;

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= M || y >= N)
    {
        return false;
    }
    return true;
}

void bfs(int X, int Y)
{
    if (map[X][Y] == false || is_visited[X][Y] == true)
        return;

    queue<pair<int, int>> q;
    q.push({ X, Y });
    is_visited[X][Y] = true;
    cnt_worm++;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny] == true || map[nx][ny] == false)
            {
                continue;
            }

            is_visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    int x, y;

    for (int i = 0; i < T; ++i)
    {
        fill_n(map[0], 51 * 51, false);
        fill_n(is_visited[0], 51 * 51, false);
        cnt_worm = 0;

        cin >> M >> N >> K;
        for (int j = 0; j < K; ++j)
        {
            cin >> x >> y;
            map[x][y] = true;
        }

        for (int x = 0; x < M; ++x)
        {
            for (int y = 0; y < N; ++y)
            {
                bfs(x, y);
            }
        }
        cout << cnt_worm << "\n";
    }

    return 0;
}