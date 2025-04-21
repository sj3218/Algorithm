#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[501][501];
int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    if (N == 1)
    {
        cin >> N;
        cout << N;
        return 0;
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> arr[i][j];
            dp[i][j] = arr[i][j];
            if (i == 1)
                continue;

            if (j == 1)
            {
                dp[i][j] += dp[i - 1][j];
            }
            else if (j == i)
            {
                dp[i][j] += dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] += max(dp[i - 1][j], dp[i - 1][j-1]);
            }

            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;
    return 0;
}