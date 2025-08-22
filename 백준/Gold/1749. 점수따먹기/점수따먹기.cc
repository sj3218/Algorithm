#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N, M;
int board[201][201];
int prefix_sum[201][201];
int dp[201][201];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    int answer = -100000000;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> board[i][j];
            prefix_sum[i][j] = board[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }

    int value;
    for (int sr = 1; sr <= N; ++sr)
    {
        for (int sc = 1; sc <= M; ++sc)
        {
            for (int er = sr; er <= N; ++er)
            {
                for (int ec = sc; ec <= M; ++ec)
                {
                    value = prefix_sum[er][ec] - prefix_sum[sr - 1][ec] - prefix_sum[er][sc - 1] + prefix_sum[sr - 1][sc - 1];
                    answer = max(answer, value);
                }
            }
        }
    }

    cout << answer;
    return 0;
}