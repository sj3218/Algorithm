
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int N;
bool has_wolf[123457];
int animal_cnt[123457];
vector<int> nodes[123457];
vector<int> trees[123457];
bool is_visited[123457];

void Input()
{
    cin >> N;
    char c;
    int node;

    for (int i = 2; i <= N; ++i)
    {
        cin >> c >> animal_cnt[i] >> node;

        if (c == 'S')
        {
            has_wolf[i] = false;
        }
        else
            has_wolf[i] = true;

        nodes[i].push_back(node);
        nodes[node].push_back(i);
    }

    //make tree
    queue<int> q;
    q.push(1);
    is_visited[1] = true;
    int curr;
    while (!q.empty())
    {
        curr = q.front(); q.pop();
        
        for (int i : nodes[curr])
        {
            if (is_visited[i])
                continue;
            q.push(i);
            trees[curr].push_back(i);
            is_visited[i] = true;
        }
    }
}

long long dfs(int curr)
{
    long long sheep_cnt = 0;
    if (!has_wolf[curr])
        sheep_cnt += animal_cnt[curr];
    else
        sheep_cnt -= animal_cnt[curr];

    for (int i : trees[curr])
    {
        sheep_cnt += dfs(i);
    }

    if (sheep_cnt < 0)
        return 0;
    return sheep_cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    cout << dfs(1);

    return 0;
}