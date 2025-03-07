#include <iostream>
using namespace std;

int T;
int N;
long long dp[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    dp[1] = 1; dp[2] = 1; dp[3] = 1;
    
    for(int i = 4; i <= 100 ; ++i)
    {
        dp[i] = dp[i-3] + dp[i-2];    
    }
    
    cin >> T;
    for(int i = 0; i< T;++i)
    {
        cin >> N;
        cout << dp[N]<<"\n";
    }
    
    return 0;
}