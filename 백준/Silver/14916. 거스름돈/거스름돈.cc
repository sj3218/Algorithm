#include <iostream>
#include <algorithm>

using namespace std;
int dp[100001];

int main()
{
    fill_n(dp, 100001, -1);
    int n;
    cin >> n;

    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;

    for (int i = 6; i <= n; ++i)
    {
        if (dp[i - 2] == -1)
        {
            dp[i] = dp[i - 5] + 1;
        }
        else if (dp[i - 5] == -1)
        {
            dp[i] = dp[i - 2] + 1;
        }
        else
        {
            dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);
        }
    }

    cout << dp[n];
    return 0;
}