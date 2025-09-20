#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;
#define INF 0X7FFFFFFF

int node_cnt;
vector<pair<int, int>> tree[100001];//dist, node
bool is_visited[100001];
int max_dist = 0;
int far_node;

void Input()
{
    cin >> node_cnt;
    int idx, connected_idx, dist;
    for (int i = 0; i < node_cnt; ++i)
    {
        cin >> idx;
        cin >> connected_idx;
        while (connected_idx != -1)
        {
            cin >> dist;
            tree[idx].push_back({ dist, connected_idx });
            cin >> connected_idx;
        }
    }
}

void dfs(int dist, int curr)
{
    is_visited[curr] = true;
    int curr_dist, node;

    if (dist > max_dist)
    {
        max_dist = dist;
        far_node = curr;
    }

    for (pair<int,int> next : tree[curr])
    {
        tie(curr_dist, node) = next;
        if (is_visited[node])
            continue;

        dfs(dist + curr_dist, node);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Input();
    
    fill_n(is_visited, 100001, false);
    max_dist = 0;
    dfs(0, 1);

    fill_n(is_visited, 100001, false);
    max_dist = 0;
    dfs(0, far_node);

    cout << max_dist;

    return 0;
}