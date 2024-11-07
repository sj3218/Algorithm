#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    fill_n(dp, 1001, 1);
    for(int i = 0; i< N; ++i)
    {
        cin >> arr[i];
    }
    
    int val;
    for(int i = 0; i< N; ++i)
    {
        val = arr[i];
        for(int j = 0; j<= i; ++j)
        {
            if(val > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    cout << *max_element(dp, dp + N);
    return 0;
}