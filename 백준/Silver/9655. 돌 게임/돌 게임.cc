#include <iostream>

using namespace std;

bool dp[1001];
int N;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N;
    
    dp[1] = true;
    dp[2] = false;
    dp[3] = true;
    
    for(int i = 4; i <=N; ++i)
    {
        dp[i] = !dp[i-3];
    }
    
    if(dp[N] == true)
    {
        cout <<"SK";
    }
    else
    {
        cout << "CY";
    }
    return 0;
}