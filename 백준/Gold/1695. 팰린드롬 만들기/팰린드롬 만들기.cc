#include <iostream>
using namespace std;
int N;
int arr[5001];
int dp[5001][5001];

int dfs(int s, int e)
{
    if(s>=e)
        return 0;
    
    if(dp[s][e] != 0)
    {
        return dp[s][e];
    }
    
    if(arr[s] == arr[e])
    {
        dp[s][e] = dfs(s + 1, e- 1);
    }
    else
    {
        dp[s][e] = min(dfs(s,e-1)+ 1, dfs(s+1, e)+1);
        
    }
    
    return dp[s][e];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i = 0; i< N; ++i)
    {
        cin >> arr[i];
    }
    
    cout <<dfs(0,N-1);
    
    return 0;
}