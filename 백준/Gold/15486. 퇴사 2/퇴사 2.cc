#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long arr[1500001][2];
long long dp[1500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i][0] >> arr[i][1];
    }


    for (int i = N - 1; i >= 0; --i)
    {
        if (i + arr[i][0] > N)
        {
            dp[i] = dp[i + 1];
            continue;
        }
        dp[i] = max(dp[i + 1], dp[i + arr[i][0]] + arr[i][1]);
    }

    cout << dp[0];
    return 0;
}