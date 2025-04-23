#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    for (int i = 2; i <= N; ++i)
    {
        int val = arr[i];
        for (int j = 1; j < i; ++j)
        {
            if (val > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + val);
            }
        }
    }

    cout << *max_element(dp+1, dp + N+1);
    return 0;
}