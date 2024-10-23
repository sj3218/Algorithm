#include <iostream>
#include <cstring>

using namespace std;
int dp[5001];

int main()
{
    memset(dp, -1, sizeof(dp));
    
    int N;
    cin >> N;
    
    dp[3] = 1;
    dp[5] = 1;
    
    for(int i = 6; i<= N; ++i)
    {
        if(dp[i-3] != -1)
        {
            dp[i] = dp[i-3] + 1;
        }
        
        if(dp[i-5] != -1)
        {
            if(dp[i] != -1)
            {
                dp[i] = min(dp[i], dp[i-5] + 1);
            }
            else
            {
                dp[i] = dp[i-5] + 1;
            }
        }
    }
    
    cout <<dp[N];
    return 0;
}