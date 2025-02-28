#include <iostream>
#include <algorithm>
#include <string>
#define INF 0x7fffffff

using namespace std;

int N;
string S;
int dp[1001];

bool FindNextBlock(int curr, int next)
{
    char curr_char = S[curr];
    char next_char = S[next];

    if (curr_char == 'B' && next_char == 'O')
    {
        return true;
    }
    else if (curr_char == 'O' && next_char == 'J')
    {
        return true;
    }
    else if (curr_char == 'J' && next_char == 'B')
    {
        return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    cin >> S;
    fill_n(dp, 1001, INF);
    dp[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        if (dp[i] == INF)
            continue;

        for (int j = i + 1; j < N; ++j)
        {
            if (FindNextBlock(i, j))
            {
                dp[j] = min(dp[j], (j - i) * (j - i) + dp[i]);
            }
        }
    }

    if (dp[N - 1] == INF)
    {
        cout << -1;
    }
    else
    {
        cout << dp[N - 1];
    }

    return 0;
}