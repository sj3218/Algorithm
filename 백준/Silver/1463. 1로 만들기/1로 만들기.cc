#include <iostream>
#include <algorithm>

using namespace std;
int N;
int dp[1000001];

int main()
{
    cin >> N;
    
    fill_n(dp, 1000001, 0);
    
    for(int i = 2; i<= N; ++i)
    {
        if(i%3 == 0)
        {
            if(i% 2 == 0)
            {
                dp[i] = min(dp[i/3], dp[i/2]);
                dp[i] = min(dp[i], dp[i-1]) + 1;
            }
            else
            {
                dp[i] = min(dp[i/3], dp[i-1]) + 1;
            }
        }
        else if(i% 2 ==0)
        {
            dp[i] = min(dp[i/2], dp[i-1]) + 1;
        }
        else
        {
            dp[i] = dp[i-1] + 1;
        }
    }
    
    cout << dp[N];
    return 0;
}