#include <iostream>
#include <string>
using namespace std;

int N, K;
string ans;
bool dp[31][31][31][450];

bool dfs(int n, int a, int b, int p)
{
    if (n == N)
    {
        if (p == K)
        {
            cout << ans;
            return true;
        }
        else
            return false;
    }

    if (dp[n][a][b][p])
        return false;

    dp[n][a][b][p] = true;
    
    ans += 'A';
    if (dfs(n + 1, a + 1, b, p))
        return true;
    ans.pop_back();

    ans += 'B';
    if (dfs(n + 1, a, b + 1, a + p))
        return true;
    ans.pop_back();

    ans += 'C';
    if (dfs(n + 1, a, b, a + b + p))
        return true;
    ans.pop_back();

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    if (!dfs(0, 0, 0, 0))
    {
        cout << -1;
    }
    return 0;
}