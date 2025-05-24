#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <string>
#define INF 0X7FFFFFFF

using namespace std;

int N, M, K;

bool board[1001][1001];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int is_visited[1001][1001][11];

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > M)
        return false;
    return true;
}

int bfs()
{
    queue<tuple<bool, int, int, int>> q; // day, k, x, y
    int cx, cy, nx, ny;
    bool is_day;
    int curr_k;
    int dist;

    is_visited[1][1][0] = 1;
    q.push({ true, 0, 1, 1 });

    while (!q.empty())
    {
        is_day = get<0>(q.front());
        curr_k = get<1>(q.front());
        cx = get<2>(q.front());
        cy = get<3>(q.front());
        dist = is_visited[cx][cy][curr_k];
        q.pop();

        if (cx == N && cy == M)
            return is_visited[cx][cy][curr_k];

        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (!IsValid(nx, ny))
                continue;

            if (board[nx][ny])
            {
                if (is_visited[nx][ny][curr_k] != INF)
                    continue;

                if (!board[cx][cy] && is_visited[nx][ny][curr_k - 1] != INF)
                    continue;

                is_visited[nx][ny][curr_k] = dist + 1;
                q.push({ !is_day, curr_k, nx, ny });
            }
            else
            {
                if (curr_k == K)
                    continue;

                if (is_visited[nx][ny][curr_k + 1] <= dist+1)
                    continue;

                if (is_day)
                {
                    //board[nx][ny] = true;
                    is_visited[nx][ny][curr_k + 1] = dist + 1;
                    q.push({ !is_day, curr_k + 1, nx, ny });
                }
                else
                {
                    //stay in same board
                    if (is_visited[cx][cy][curr_k] == dist + 1)
                        continue;
                    is_visited[cx][cy][curr_k]++;
                    q.push({ !is_day, curr_k, cx, cy });
                }
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(&is_visited[0][0][0], 1001 * 1001 * 11, INF);
    cin >> N >> M >> K;
    string line;
    for (int i = 1; i <= N; ++i)
    {
        cin >> line;
        for (int j = 1; j <= M; ++j)
        {
            if (line[j - 1] == '0')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }
    cout << bfs();

    return 0;
}
