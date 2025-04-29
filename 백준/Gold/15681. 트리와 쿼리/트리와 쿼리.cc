#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, R, Q;
int u, v;
int U;
vector<vector<int>> tree(100001);
int dp[100001];
bool is_visited[100001];

void dfs(int root)
{
    is_visited[root] = true;
    dp[root] = 1;

    for (int next : tree[root])
    {
        if (is_visited[next])
            continue;

        dfs(next);
        dp[root] += dp[next];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(R);

    for (int i = 0; i < Q; ++i)
    {
        cin >> U;
        cout << dp[U] << "\n";
    }
    return 0;
}