#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;

int N;
long long board[100001][3];
long long dp[100001][3];
const int INF = 0X7FFFFFFF;

void Input()
{
    fill_n(&board[0][0], 100001 * 3, -1);
    fill_n(&dp[0][0], 100001 * 3, INF);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> board[i][j];
        }
    }
}

int Solution()
{
    int curr = board[0][1];
    dp[0][1] = curr;
    dp[0][2] = curr + board[0][2];
    for (int r = 1; r < N; ++r)
    {
        dp[r][0] = min(dp[r - 1][0], dp[r - 1][1]) + board[r][0];
        dp[r][1] = min({ dp[r - 1][0], dp[r - 1][1], dp[r - 1][2], dp[r][0]}) + board[r][1];
        dp[r][2] = min({ dp[r - 1][1], dp[r - 1][2], dp[r][1]}) + board[r][2];
    }

    return dp[N-1][1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int num = 1;
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;

        Input();
        cout << num << ". " << Solution();
        cout << "\n";
        ++num;
    }

    return 0;
}