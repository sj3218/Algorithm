#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N;
pair<int, int> mat[501];
int dp[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    fill_n(&dp[0][0], 501 * 501, INF);
    cin >> N;
    int r, c;
    for (int i = 1; i <= N; ++i)
    {
        cin >> r >> c;
        mat[i] = { r,c };
        dp[i][i] = 0;
    }

    /*
    dp[i][j] = dp[i][k] + dp[k+ 1][j] + mat[i].r * mat[k].c * mat[j].c;
    */
    int j = 0;
    for (int len = 1; len < N; ++len)
    {
        for (int i = 1; i + len <= N; ++i)
        {
            j = i + len;
            for (int k = i; k < j; ++k)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mat[i].first * mat[k].second * mat[j].second);
            }
        }
    }

    cout << dp[1][N];
    return 0;
}