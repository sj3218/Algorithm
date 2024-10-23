#include <iostream>
#include <cstring>

using namespace std;

int dp[1000001];

int main()
{
    int N;
    cin >> N;
    memset(dp, -1, sizeof(dp));

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= N; ++i)
    {
        if (i % 3 == 0)
        {
            dp[i] = dp[i / 3] + 1;
        }

        if (i % 2 == 0)
        {
            if (dp[i] != -1)
            {
                dp[i] = min(dp[i], dp[i / 2] + 1);
            }
            else
            {
                dp[i] = dp[i / 2] + 1;
            }
        }

        if (dp[i] == -1)
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }

    }

    cout << dp[N];
    return 0;
}