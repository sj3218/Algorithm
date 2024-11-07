#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[10001];
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
    }

    fill_n(dp, 10001, 0);

    dp[1] = arr[1];
    dp[2] = arr[2] + arr[1];
    dp[3] = max(max(arr[1], arr[2]) + arr[3], dp[2]);


    for (int i = 4; i <= N; ++i)
    {
        dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
        dp[i] = max(dp[i], dp[i - 1]);
        //dp[i] = max(dp[i - 2], dp[i - 4] + arr[i - 3] + arr[i - 1]) + arr[i];
    }

    cout << *max_element(dp, dp + N+1);

    return 0;
}