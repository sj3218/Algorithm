#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int town_cnt;
int people_cnt[10001];
vector<vector<int>> towns(10001);
bool is_visited[10001];
int dp[10001][2]; // 0: not selected, 1 : selected

void dfs(int curr)
{
    is_visited[curr] = true;
    dp[curr][0] = 0;
    dp[curr][1] = people_cnt[curr];

    for (int next : towns[curr])
    {
        if (is_visited[next])
            continue;

        dfs(next);
        dp[curr][0] += max(dp[next][0], dp[next][1]);
        dp[curr][1] += dp[next][0];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> town_cnt;
    
    for (int i = 1; i <= town_cnt; ++i)
    {
        cin >> people_cnt[i];
    }

    int a, b;
    for (int i = 1; i < town_cnt; ++i)
    {
        cin >> a >> b;
        towns[a].push_back(b);
        towns[b].push_back(a);
    }
    dfs(1);

    cout << max(dp[1][0], dp[1][1]);

    return 0;
}