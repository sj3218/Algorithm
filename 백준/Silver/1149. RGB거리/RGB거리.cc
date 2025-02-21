#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1001][3];
int dp[1001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i = 0; i< N; ++i)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];
    
    int r,g,b;
    for(int i = 1; i< N; ++i)
    {
        r = dp[i-1][0];
        g = dp[i-1][1];
        b = dp[i-1][2];
        dp[i][0] = min(g,b) + arr[i][0];
        dp[i][1] = min(r,b) + arr[i][1];
        dp[i][2] = min(r,g) + arr[i][2];
    }
    int result = min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    
    cout << result;
    return 0;
}