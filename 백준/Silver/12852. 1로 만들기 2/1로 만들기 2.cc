#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int dp[1000001];
int idx[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    dp[1] = 0;

    for (int i = 2; i <= N; ++i)
    {
        dp[i] = dp[i - 1];
        idx[i] = i - 1;

        if (i % 2 == 0)
        {
            if (dp[i] > dp[i / 2])
            {
                dp[i] = dp[i / 2];
                idx[i] = i / 2;
            }
        }

        if (i % 3 == 0)
        {
            if (dp[i] > dp[i / 3])
            {
                dp[i] = dp[i / 3];
                idx[i] = i / 3;
            }
        }

        dp[i] += 1;
    }


    cout << dp[N] <<"\n";
    int index = N;
    while (index != 0)
    {
        cout << index << " ";
        index = idx[index];
    }
    return 0;
}