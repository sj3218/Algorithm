
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N;
int weight[10001];
vector<vector<int>> tree(10001);
bool is_visited[10001];
int dp[10001][2];
vector<int> answer;

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> weight[i];
    }

    int a, b;
    for (int i = 1; i < N; ++i)
    {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
}

void dfs(int curr)
{
    is_visited[curr] = true;
    dp[curr][0] = 0;
    dp[curr][1] = weight[curr];

    for (int next : tree[curr])
    {
        if (is_visited[next])
            continue;

        dfs(next);
        dp[curr][0] += max(dp[next][0], dp[next][1]);
        dp[curr][1] += dp[next][0];
    }
}

void Backtracking(int curr, bool parent_selected)
{
    bool curr_selected = false;
    is_visited[curr] = true;
    if (!parent_selected && dp[curr][0] < dp[curr][1])
    {
        answer.push_back(curr);
        curr_selected = true;
    }

    for (int next : tree[curr])
    {
        if (is_visited[next])
            continue;
        Backtracking(next, curr_selected);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    dfs(1);
    cout << max(dp[1][0], dp[1][1])<<"\n";

    fill_n(is_visited, 10001, false);
    Backtracking(1, false);
    sort(answer.begin(), answer.end());
    for (int i : answer)
    {
        cout << i << " ";
    }

    return 0;
}