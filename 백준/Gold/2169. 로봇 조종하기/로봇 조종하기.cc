#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N, M;
int board[1001][1001];
bool is_visited[1001][1001][3];
int dr[3] = { 0,0,1 };
int dc[3] = { 1,-1, 0 };
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= M; ++i)
    {
        dp[1][i] = dp[1][i - 1] + board[1][i];
    }

    vector<int> left(M+2);
    vector<int> right(M+2);
    
    for (int i = 2; i <= N; ++i)
    {
        left[0] = dp[i-1][1];
        right[M + 1] = dp[i - 1][M];

        for (int j = 1; j <= M; ++j)
        {
            left[j] = max(left[j - 1], dp[i-1][j]) + board[i][j];
        }
        for (int j = M; j > 0; --j)
        {
            right[j] = max(right[j + 1], dp[i-1][j]) + board[i][j];
        }

        for (int j = 1; j <= M; ++j)
        {
            dp[i][j] = max(left[j], right[j]);
        }
    }

    cout << dp[N][M];
    return 0;
}