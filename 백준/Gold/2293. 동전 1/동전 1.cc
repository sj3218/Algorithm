#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, K;
int dp[10001];
int coins[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    
    fill_n(dp, 10001, 0);
    fill_n(coins, 101, 0);
    
    for(int i = 0; i< N; ++i)
    {
        cin >> coins[i];
    }
    
    dp[0] = 1;
    for(int i = 0; i< N; ++i)
    {
        int coin = coins[i];
        for(int j = coin; j <= K; ++j)
        {
            dp[j] += dp[j - coin];
        }
    }
    
    cout << dp[K];
    return 0;
}