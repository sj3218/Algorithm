#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N;

int costs[1001][3];
int dp[1001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    //int R, G, B;
    for (int i = 0; i < N; ++i)
    {
        cin >> costs[i][0] >> costs[i][1] >> costs[i][2];
    }

    int answer = INF;
    for (int i = 0; i < 3; ++i)
    {
        fill_n(&dp[0][0], 1001 * 3, INF);

        dp[0][i] = costs[0][i];

        for (int j = 1; j < N; ++j)
        {
            if (dp[j - 1][1] == INF && dp[j - 1][2] == INF)
                dp[j][0] = INF;
            else
                dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + costs[j][0];

            if (dp[j - 1][0] == INF && dp[j - 1][2] == INF)
                dp[j][1] = INF;
            else
                dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + costs[j][1];

            if (dp[j - 1][0] == INF && dp[j - 1][1] == INF)
                dp[j][2] = INF;
            else
                dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + costs[j][2];
        }

        for (int end = 0; end < 3; ++end)
        {
            if (end == i)
                continue;
            answer = min(answer, dp[N - 1][end]);
        }
    }

    cout << answer;

    return 0;
}