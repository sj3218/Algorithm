#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N;
char board[51][51];
int dp[51][51][4];
bool is_visited[51][51][4];

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > N || c > N)
        return true;
    return false;
}

int bfs(pair<int,int> start, pair<int,int> end)
{
    fill_n(&dp[0][0][0], 4 * 51 * 51, INF);
    fill_n(&is_visited[0][0][0], 4 * 51 * 51, false);

    int r, c, nr, nc;
    int dir, cnt;
    int cost;
    int answer = INF;

    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;//cost, r, c, dir
    tie(r, c) = start;
    for (int i = 0; i < 4; ++i)
    {
        pq.push({ 0, r, c, i });
        dp[r][c][i] = 0;
    }

    while (!pq.empty())
    {
        tie(cnt, r, c, dir) = pq.top(); pq.pop();
        is_visited[r][c][dir] = true;

        if (r == end.first && c == end.second)
        {
            answer = min(answer, cnt);
            continue;
        }

        nr = r + dr[dir];
        nc = c + dc[dir];

        if (OutOfBound(nr, nc) || board[nr][nc] == '*' || is_visited[nr][nc][dir])
            continue;

        if (board[nr][nc] == '!')
        {
            cost = cnt + 1;
            if (dir == 0 || dir == 1)
            {
                dp[nr][nc][2] = cost;
                dp[nr][nc][3] = cost;
                pq.push({ cost, nr, nc, 2 });
                pq.push({ cost, nr, nc, 3 });
            }
            else
            {
                dp[nr][nc][0] = cost;
                dp[nr][nc][1] = cost;
                pq.push({ cost, nr, nc, 0 });
                pq.push({ cost, nr, nc, 1 });
            }
        }

        dp[nr][nc][dir] = cnt;
        pq.push({ cnt, nr ,nc, dir });
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    string s;
    vector<pair<int, int>> doors;
    for (int i = 1; i <= N; ++i)
    {
        cin >> s;
        for (int j = 1; j <= N; ++j)
        {
            board[i][j] = s[j - 1];
            if (board[i][j] == '#')
            {
                doors.push_back({ i,j });
            }
        }
    }

    cout << bfs(doors[0], doors[1]);
    return 0;
}