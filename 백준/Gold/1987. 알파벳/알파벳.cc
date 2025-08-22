#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int R, C;
char board[21][21];
bool is_visited[21][21];
bool is_visited_char[31];

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > R || c > C)
        return true;
    return false;
}

int dfs(int r, int c)
{
    int ans = 0;
    int nr, nc, idx;
    int sum[4] = { 0, };

    for (int i = 0; i < 4; ++i)
    {
        nr = r + dr[i];
        nc = c + dc[i];
        if (OutOfBound(nr, nc) || is_visited[nr][nc])
            continue;

        idx = board[nr][nc] - 'A';
        if (is_visited_char[idx])
            continue;

        is_visited[nr][nc] = true;
        is_visited_char[idx] = true;
        sum[i] = dfs(nr, nc);
        is_visited[nr][nc] = false;
        is_visited_char[idx] = false;
    }

    ans = max({ sum[0], sum[1], sum[2], sum[3] });

    return ans + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> R >> C;

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cin >> board[i][j];
        }
    }

    int idx = board[1][1] - 'A';
    is_visited[1][1] = true;
    is_visited_char[idx] = true;
    cout << dfs(1, 1);

    return 0;
}