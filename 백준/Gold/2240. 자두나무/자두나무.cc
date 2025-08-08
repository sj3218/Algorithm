#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <map>

#define INF 0X7FFFFFFF
using namespace std;

int T, W;
int tree_num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T >> W;
    int dp[1001][31][3];
    fill_n(&dp[0][0][0], 1001 * 31 * 3, 0);

    for (int i = 1; i <= T; ++i)
    {
        cin >> tree_num;
        if (tree_num == 1)
            dp[i][0][1] = dp[i - 1][0][1] + 1;

        for (int j = 1; j <= i && j<= W; ++j)
        {
            //not move
            if (tree_num == 1)
            {
                dp[i][j][1] = max(dp[i - 1][j - 1][2], dp[i - 1][j][1]) + 1;
             
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]);
            }
            else
            {
                dp[i][j][2] = max(dp[i - 1][j][2], dp[i - 1][j - 1][1]) + 1;

                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i <= W; ++i)
    {
        answer = max({ answer, dp[T][i][1],dp[T][i][2] });
    }
    cout << answer;
    return 0;
}