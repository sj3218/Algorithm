#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int N;
int num[201];
int dp[201];

void Input()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> num[i];
    }
}

void Solution()
{
    for (int i = 0; i < N; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (num[i] > num[j])
                if (dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
        }
    }

    cout << N - *max_element(dp, dp + N);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();

    return 0;
}