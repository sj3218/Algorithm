#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

const int divide_value = 1000000003;
int N, K;
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    for (int i = 0; i <= N; ++i)
    {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 2; j <= K; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 2][j - 1];
            dp[i][j] %= divide_value;
        }
    }

    int answer = dp[N-3][K-1] + dp[N-1][K];
    answer %= divide_value;
    cout << answer;
    return 0;
}