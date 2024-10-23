#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];
int N;
int arr[100001];

void Input()
{
    cin >> N;
    fill_n(arr, 100001, -1);
    fill_n(dp, 100001, -1);
    
    for(int i = 0; i< N; ++i)
    {
        cin >>arr[i];
    }
}


int main()
{
    Input();
    int M = 0;
    
    dp[0] = arr[0];
    M = dp[0];
    
    for(int i = 1; i<N; ++i)
    {
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        if(M < dp[i])
        {
            M = dp[i];
        }
    }
    
    cout<<M;
    return 0;
}