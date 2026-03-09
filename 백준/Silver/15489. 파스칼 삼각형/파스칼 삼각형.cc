#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;
int R, C, W;
int dp[31][31];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> R >> C >> W;
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 1;

    int r_size = R + W;
    for (int i = 3; i < r_size; ++i)
    {
        dp[i][1] = 1;
        dp[i][i] = 1;
        for (int j = 2; j < i; ++j)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    int sum = 0;
    int idx = 0;
    for (int i = R; i < r_size; ++i)
    {
        for (int j = C; j <= C + idx; ++j)
        {
            sum += dp[i][j];
        }

        ++idx;
    }

    cout << sum;

    return 0;
}