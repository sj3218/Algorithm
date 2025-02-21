#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int dp[41][2];

void dfs(int n)
{
    if(n < 0)
        return;
    
    if(dp[n][0] != -1)
    {
        return;
    }
    
    if(dp[n-1][0] == -1)
    {
        dfs(n-1); 
    }
    if(dp[n-2][0] == -1)
    {
        dfs(n-2);
    }
    
    dp[n][0] = dp[n-1][0] + dp[n-2][0];
    dp[n][1] = dp[n-1][1] + dp[n-2][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    fill_n(dp[0], 41*2, -1);
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    
    cin >> T;
    for(int i = 0; i< T; ++i)
    {
        cin >> N;
        
        dfs(N);
        cout << dp[N][0] <<" "<<dp[N][1]<<"\n";
        
    }
    return 0;
}