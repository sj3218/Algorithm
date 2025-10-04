#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

int friend_cnt;
vector<vector<int>> friends;
int dp[1000001][2];//0 : x, 1 : o
bool is_visited[1000001];

void Init()
{
    cin >> friend_cnt;
    friends = vector<vector<int>>(friend_cnt+1);

    int u, v;
    for (int i = 1; i < friend_cnt; ++i)
    {
        cin >> u >> v;
        friends[u].push_back(v);
        friends[v].push_back(u);
    }
}

void dfs(int idx)
{
    is_visited[idx] = true;

    dp[idx][0] = 0;
    dp[idx][1] = 1;

    for (int child : friends[idx])
    {
        if (is_visited[child])
            continue;

        dfs(child);
        
        //not early adapter
        dp[idx][0] += dp[child][1];
        //early adapter
        dp[idx][1] += min(dp[child][0], dp[child][1]); 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Init();
    is_visited[1] = true;
    dfs(1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}