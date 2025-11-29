#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001];
int test_case;
int num;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    dp[0] = 1;

    for (int coin = 1; coin <= 3; ++coin)
    {
        for (int i = coin; i < 10001; ++i)
        {
            dp[i] += dp[i - coin];
        }
    }

    cin >> test_case;
    while (test_case--)
    {
        cin >> num;
        cout << dp[num] << "\n";
    }
    return 0;
}