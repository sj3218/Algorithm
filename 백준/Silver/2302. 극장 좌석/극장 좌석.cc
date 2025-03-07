#include <iostream>
using namespace std;

int N, M;
int vip_idx;
long long dp[41];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 40; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    int pre_vip_idx = 0;
    int ans = 1;
    for (int i = 0; i < M; ++i)
    {
        cin >> vip_idx;
        ans *= dp[vip_idx - pre_vip_idx - 1];
        pre_vip_idx = vip_idx;
    }

    ans *= dp[N - pre_vip_idx];

    cout << ans;
    return 0;
}