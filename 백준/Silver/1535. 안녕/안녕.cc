#include <iostream>
#include <vector>

using namespace std;
#define HEALTH 100

int N;
vector<int> L;
vector<int> J;
vector<vector<int>> dp;

void Input()
{
    cin >> N;

    L.assign(N + 1, 0);
    J.assign(N + 1, 0);
    dp.assign(N + 1, vector<int>(HEALTH + 2, 0));

    int val;
    for (int i = 1; i <= N; ++i)
    {
        cin >> L[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        cin >> J[i];
    }
}


int main()
{
    Input();

    for (int i = 1; i <= N; ++i)
    {
        int life = L[i];
        int joy = J[i];

        for (int j = 1; j <= HEALTH; ++j)
        {
            if (j < life)
            {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = max(dp[i - 1][j], joy + dp[i - 1][j - life]);
        }
    }

    cout << dp[N][99];
    return 0;
}