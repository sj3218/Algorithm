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
    
    fill_n(dp, 10001, INT_MAX);
    fill_n(coins, 101, 0);
    
    for(int i = 0; i< N; ++i)
    {
        cin >> coins[i];
    }
    
    dp[0] = 0;
    for(int i = 0; i< N; ++i)
    {
        int coin = coins[i];
        for(int j = coin; j <= K; ++j)
        {
            if(dp[j-coin] == INT_MAX)
                continue;
            dp[j] = min(dp[j], dp[j-coin] + 1);
        }
    }
    
    if(dp[K] == INT_MAX)
    {
        cout << "-1";
    }
    else
        cout << dp[K];
    return 0;
}