#include <iostream>
#include <cstring>
#define DIV 1000000007

using namespace std;

int S;
int arr[3];

long long dp[51][51][51][51]; // S, dotorya, kesakiyo, hongjun

long long dfs(int s, int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
    {
        return 0;
    }

    if (s == 0)
    {
        if (a == 0 && b == 0 && c == 0)
        {
            return 1;
        }
        return 0;
    }

    long long ans = dp[s][a][b][c];
    if (ans != -1)
    {
        return ans;
    }

    ans = 0;
    ans += dfs(s - 1, a - 1, b, c);
    ans += dfs(s - 1, a, b - 1, c);
    ans += dfs(s - 1, a, b, c - 1);
    ans += dfs(s - 1, a - 1, b - 1, c);
    ans += dfs(s - 1, a - 1, b, c - 1);
    ans += dfs(s - 1, a, b - 1, c - 1);
    ans += dfs(s - 1, a - 1, b - 1, c - 1);

    ans %= DIV;
    dp[s][a][b][c] = ans;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    memset(dp, -1, sizeof(dp));

    cin >> S;
    for (int i = 0; i < 3; ++i)
    {
        cin >> arr[i];
    }

    cout << dfs(S, arr[0], arr[1], arr[2]);

    return 0;
}