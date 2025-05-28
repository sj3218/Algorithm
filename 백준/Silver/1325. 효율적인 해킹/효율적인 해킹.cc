#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
int N, M;
vector<vector<int>> networks(10001);
int dp[10001];
bool is_visited[10001];
int cnt_max = 0;

void dfs(int computer)
{
    is_visited[computer] = true;

    dp[computer]++;
    cnt_max = max(cnt_max, dp[computer]);

    for (int next : networks[computer])
    {
        if (is_visited[next])
            continue;
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        networks[a].push_back(b);
    }

    int cnt;
    for (int i = 1; i <= N; ++i)
    {
        fill_n(is_visited, 10001, false);
        dfs(i);
    }

    for (int i = 1; i <= N; ++i)
    {
        if (cnt_max == dp[i])
        {
            cout << i << " ";
        }
    }

    return 0;
}
