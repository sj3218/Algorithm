#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, M;
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;

    int coin;
    while (T--)
    {
        cin >> N;
        vector<int> coins;
        fill_n(dp, 10001, 0);
        for (int i = 0; i < N; ++i)
        {
            cin >> coin;
            coins.push_back(coin);
        }

        cin >> M;
        dp[0] = 1;

        for (int coin : coins)
        {
            for (int i = coin; i <= M; ++i)
            {
                dp[i] += dp[i - coin];
            }
        }

        cout << dp[M] << "\n";
    }

    return 0;
}