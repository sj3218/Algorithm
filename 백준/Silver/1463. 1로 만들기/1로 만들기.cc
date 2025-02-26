#include <iostream>
#define INF 0X7FFFFFFF
int dp[1000001];
int N;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= N; ++i)
    {
        int ans = INF;
        if (i % 3 == 0)
        {
            ans = min(ans, dp[i / 3] + 1);
        }

        if (i % 2 == 0)
        {
            ans = min(ans, dp[i / 2] + 1);
        }

        ans = min(ans, dp[i - 1] + 1);
        dp[i] = ans;
    }

    cout << dp[N];
    return 0;
}