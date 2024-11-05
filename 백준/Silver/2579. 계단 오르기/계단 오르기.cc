#include <iostream>
#include <algorithm>
using namespace std;

int N; 
int arr[301];
int dp[301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    fill_n(dp, 301, -1);
    
    cin >> N;
    for(int i = 1; i<= N;++i)
    {
        cin >> arr[i];
    }
    
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    dp[3] = max(arr[2], arr[1]) + arr[3];
    
    for(int i = 4; i<= N; ++i)
    {
        dp[i] = max(dp[i-3] + arr[i-1], dp[i-2]) + arr[i];
    }
    
    cout << dp[N];
    return 0;
}