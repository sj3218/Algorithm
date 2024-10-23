#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1001];
int arr[1001];

void Input()
{
    cin >>N;
    fill_n(dp, 1001, 1);
    fill_n(arr, 1001, 0);
    
    for(int i = 0; i< N; ++i)
    {
        cin >> arr[i];
    }
}
int main()
{
    Input();
    
    
    for(int i = 1; i < N; ++i)
    {
        int val = arr[i];
        int m = 0;
        for(int j = 0; j<i; ++j)
        {
            if(val > arr[j])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    
    int ans = *max_element(dp, dp+N);
    cout <<ans;
    return 0;
}