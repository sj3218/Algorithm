#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;
int dp[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    dp[0] = 1;
    for (int i = 1; i <= 10; ++i)
    {
        dp[i] = i * dp[i - 1];
    }

    int answer = 0;
    answer = dp[N] / (dp[N - K] * dp[K]);
    cout << answer;

    return 0;
}