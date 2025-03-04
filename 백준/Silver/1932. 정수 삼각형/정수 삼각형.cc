#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[501][501];
int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    int ans = dp[0][0];

    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i + 1; ++j)
        {
            int left = 0;
            int right = 0;
            if (j == 0)
            {
                right = dp[i - 1][j];
            }
            else if (j == i)
            {
                left = dp[i - 1][j - 1];
            }
            else
            {
                left = dp[i - 1][j - 1];
                right = dp[i - 1][j];
            }

            dp[i][j] = max(right, left) + arr[i][j];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}