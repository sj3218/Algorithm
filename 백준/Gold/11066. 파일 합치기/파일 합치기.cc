#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;
#define INF 0X7FFFFFFF

int test_case;
int K;
int values[501];
int dp[501][501];
int sum[501][501];

void Input()
{
    cin >> K;
    for (int i = 1; i <= K; ++i)
    {
        cin >> values[i];
        dp[i][i] = 0;
    }

    for (int i = 1; i <= K; ++i)
    {
        sum[i][i] = values[i];
        for (int j = i + 1; j <= K; ++j)
        {
            sum[i][j] = sum[i][j - 1] + values[j];
        }
    }

}

void solution()
{
    for (int len = 1; len < K; ++len)
    {
        for (int i = 1; i + len <= K; ++i)
        {
            int j = i + len;

            for (int k = i; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[i][j]);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> test_case;

    for (int t = 0; t < test_case; ++t)
    {
        fill_n(&dp[0][0], 501 * 501, INF);
        Input();
        solution();
        cout << dp[1][K]<<"\n";
    }
    return 0;
}