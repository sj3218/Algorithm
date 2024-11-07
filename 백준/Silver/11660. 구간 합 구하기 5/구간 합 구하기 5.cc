#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[1025][1025];
int dp[1025][1025];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(dp[0], 1025*1025, 0);
    
    cin >> N >> M;
    for(int i = 1; i<= N; ++i)
    {
        for(int j = 1; j<=N; ++j)
        {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j] + dp[i][j-1] + (dp[i-1][j] - dp[i-1][j-1]);
        }
    }
    
    int x1, x2, y1, y2;
    
    for(int i = 0; i< M ; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int ans = dp[x2][y2];
        
        ans += dp[x1-1][y1-1]-(dp[x1-1][y2] + dp[x2][y1-1]);
        cout <<ans <<"\n";
    }

    
    return 0;
}