#include <iostream>
#include <algorithm>
#define MAX 0X7FFFFFFF
using namespace std;

int dp[50001];
int N;
void Input()
{
    cin >> N;
    fill_n(dp, 50001, MAX);
}
int main()
{
    Input();

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 1; j * j <= i; ++j)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }

    cout << dp[N];
    return 0;
}