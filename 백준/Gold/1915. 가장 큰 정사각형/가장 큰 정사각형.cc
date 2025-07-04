#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
bool board[1001][1001];
int dp[1001][1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    int max_length = 0;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> s;
        for (int j = 1; j <= M; ++j)
        {
            if (s[j - 1] == '1')
            {
                board[i][j] = true;

                if (board[i - 1][j] && board[i][j - 1] && board[i - 1][j - 1])
                {
                    dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
                    dp[i][j] += 1;
                }
                else
                    dp[i][j] = 1;

                max_length = max(max_length, dp[i][j]);
            }
        }
    }

    cout << max_length * max_length;

    return 0;
}