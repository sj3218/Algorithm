#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int u, v, dis;
vector<vector<int>> tree(1001);
int dp[1001][1001];
bool is_visited[1001];

int dfs(int x, int y)
{
    is_visited[x] = true;

    if (dp[x][y] != -1)
        return dp[x][y];

    int answer = 0;
    for (int next : tree[x])
    {
        if (is_visited[next] == true)
            continue;

        answer = dfs(next, y);
        if (answer != 0)
        {
            answer += dp[next][x];
            break;
        }
    }

    /*if (answer != 0)
    {
        dp[x][y] = answer;
        dp[y][x] = answer;
    }*/
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    fill_n(dp[0], 1001 * 1001, -1);

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> u >> v >> dis;
        tree[u].push_back(v);
        tree[v].push_back(u);
        dp[u][v] = dis;
        dp[v][u] = dis;
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> u >> v;
        if (dp[u][v] != -1)
            cout << dp[u][v] << "\n";
        else if (u == v)
            cout << "0\n";
        else
        {
            fill_n(is_visited, 1001, false);
            cout << dfs(u, v)<<"\n";
        }
    }

    return 0;
}
