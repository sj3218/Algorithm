#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N;
int dp[100001];
vector<vector<int>> tree(100001);

void bfs()
{
    dp[1] = 0;
    queue<int> q;
    q.push(1);

    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (int next : tree[cur])
        {
            if (dp[next] != -1)
                continue;

            dp[next] = cur;
            q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;

    fill_n(dp, 100001, -1);

    int u, v;
    for (int i = 1; i < N; ++i)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    bfs();


    for (int i = 2; i <= N; ++i)
    {
        cout << dp[i] << "\n";
    }

    return 0;
}