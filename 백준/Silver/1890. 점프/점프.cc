#include <iostream>
#include <algorithm>

using namespace std;
int N;
int arr[101][101];
long long dp[101][101];

void Input()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }

    fill_n(dp[0], 101 * 101, 0);

    dp[0][0] = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int val = arr[i][j];
            int right = val + j;
            int down = val + i;

            if (dp[i][j] == 0 || arr[i][j] == 0)
                continue;

            if (right < N)
                dp[i][right] = dp[i][right] + dp[i][j];

            if (down < N)
            {
                dp[down][j] = dp[i][j] + dp[down][j];
            }
        }
    }

    cout << dp[N - 1][N - 1];
    return 0;
}