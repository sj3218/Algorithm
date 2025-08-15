#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N, M;
string s;
bool board[1001][1001];

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
bool is_visited[1001][1001];
pair<int,int> dp[1001][1001]; //index, cnt

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > N || c > M)
        return true;
    return false;
}

void bfs(int r, int c, int idx)
{
    vector<pair<int, int>> pos;
    queue<pair<int, int>> q;
    q.push({ r,c });
    is_visited[r][c] = true;

    int nr, nc;
    int cnt = 0;
    while (!q.empty())
    {
        tie(r, c) = q.front(); q.pop();
        ++cnt;
        pos.push_back({ r,c });
        for (int i = 0; i < 4; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];

            if (OutOfBound(nr, nc) || is_visited[nr][nc] || board[nr][nc] == false)
                continue;

            is_visited[nr][nc] = true;
            q.push({ nr,nc });
        }
    }

    for (pair<int, int> next : pos)
    {
        tie(r, c) = next;
        dp[r][c] = { idx, cnt };
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> s;
        for (int j = 1; j <= M; ++j)
        {
            if (s[j - 1] == '0')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }

    int idx = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (board[i][j] && is_visited[i][j] == false)
                bfs(i, j, ++idx);
        }
    }

    int cnt = 0;
    int nr, nc;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            if (board[i][j])
                cout << "0";
            else
            {
                cnt = 1;
                vector<int> check;

                for (int k = 0; k < 4; ++k)
                {
                    bool is_included = false;

                    nr = i + dr[k];
                    nc = j + dc[k];

                    if (OutOfBound(nr, nc) || board[nr][nc] == false)
                        continue;

                    for (int next : check)
                    {
                        if (next == dp[nr][nc].first)
                        {
                            is_included = true;
                            break;
                        }
                    }

                    if (!is_included)
                    {
                        cnt += dp[nr][nc].second;
                        check.push_back(dp[nr][nc].first);
                    }
                }
                cnt %= 10;
                cout << cnt;
            }
        }
        cout << "\n";
    }
    return 0;
}