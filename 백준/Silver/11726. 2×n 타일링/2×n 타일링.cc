#include <iostream>
#include <cstring>
#define MOD 10007
using namespace std;

int dp[1001];
int N;
void Input()
{
    cin >> N;
    memset(dp, -1, sizeof(dp));
}
int main()
{
    Input();
    
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i<= N; ++i)
    {
        dp[i] = (dp[i-1]+ dp[i-2]) % MOD;
    }
    
    cout << dp[N];
    return 0;
}