#include <iostream>
#include <cstring>

using namespace std;

int N;
int dp[301];
int stairs[301];

void Input()
{
    cin >> N;

    memset(dp, -1, sizeof(dp));
    memset(stairs, -1, sizeof(stairs));

    for (int i = 1; i <= N; ++i)
    {
        cin >> stairs[i];
    }
}

int main()
{
    Input();
    dp[1] = stairs[1];
    dp[2] = stairs[2] + stairs[1];
    dp[3] = max(stairs[1], stairs[2]) + stairs[3];

    for (int i = 4; i <= N; ++i)
    {
        dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i]);
    }

    cout << dp[N];
    return 0;
}