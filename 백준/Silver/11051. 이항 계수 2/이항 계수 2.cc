#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;
#define DIVIDE 10007

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i <= 1000; ++i)
    {
        dp[i][0] = 1;
        dp[i][i] = 1;
    }

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            dp[i][j] %= DIVIDE;
        }
    }

    cout << dp[N][K];

    return 0;
}