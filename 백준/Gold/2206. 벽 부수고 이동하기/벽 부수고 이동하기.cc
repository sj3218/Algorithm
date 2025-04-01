#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

int N, M;
int map[1001][1001];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0,0 };

int is_visited[1001][1001][2];

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > M)
    {
        return false;
    }
    return true;
}

void bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({ 1,1, false });
    is_visited[1][1][0] = 1;

    while (!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int already_broken = get<2>(q.front());
        int cnt_path = is_visited[x][y][already_broken];
        q.pop();
        if (x == N && y == M)
            return;

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!IsValid(nx, ny))
                continue;

            if (map[nx][ny] == 1)
            {
                if (already_broken == 1)
                {
                    continue;
                }
                else
                {
                    if (is_visited[nx][ny][already_broken] == -1)
                    {
                        q.push({ nx, ny, 1 });
                        is_visited[nx][ny][1] = cnt_path + 1;
                    }
                }
            }
            else
            {
                if (is_visited[nx][ny][already_broken] == -1)
                {
                    q.push({ nx, ny, already_broken });
                    is_visited[nx][ny][already_broken] = cnt_path + 1;
                }
                
            }

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(is_visited[0][0], 1001 * 1001 * 2, -1);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; ++j)
        {
            map[i][j + 1] = s[j]-'0';
        }
    }

    bfs();
    
    if (is_visited[N][M][0] == -1)
    {
        if (is_visited[N][M][1] == -1)
            cout << -1;
        else
            cout << is_visited[N][M][1];
    }
    else
    {
        if (is_visited[N][M][1] == -1)
            cout << is_visited[N][M][0];
        else
            cout << min(is_visited[N][M][0], is_visited[N][M][1]);
    }
    return 0;
}