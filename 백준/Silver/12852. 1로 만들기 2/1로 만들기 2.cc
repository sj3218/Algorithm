#include <iostream>
#define INF 0x7fffffff
using namespace std;

int N;
int dp[1000001][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    dp[1][0] = 0;
    dp[1][1] = 0;
    
    for (int i = 2; i <= N; ++i)
    {
        int temp = INF;
        int pre_num = 0;

        if (i % 3 == 0)
        {
            temp = dp[i / 3][0] + 1;
            pre_num = i / 3;
        }

        if (i % 2 == 0)
        {
            if (temp > dp[i / 2][0])
            {
                temp = dp[i / 2][0] + 1;
                pre_num = i / 2;
            }
        }

        if (temp > dp[i - 1][0])
        {
            temp = dp[i - 1][0] + 1;
            pre_num = i - 1;
        }

        dp[i][0] = temp;
        dp[i][1] = pre_num;
    }

    cout << dp[N][0] << "\n";
    cout << N << " ";


    int num = dp[N][1];
    while (num >= 1)
    {
        cout << num << " ";
        num = dp[num][1];
    }
    return 0;
}