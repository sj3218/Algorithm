#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;
int cnt_nodes;
vector<vector<int>> tree(51);
int erase_node;
int total_leaf_node;
int parent_idx[51];

void bfs()
{
    queue<int> q;
    q.push(erase_node);
    int idx;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (parent_idx[curr] == -1)
        {
            total_leaf_node = 0;
            return;
        }

        if (tree[curr].size() == 0)
        {
            idx = parent_idx[curr];
            if (tree[idx].size() == 1)
            {
                continue;
            }
            --total_leaf_node;
        }

        for (int next : tree[curr])
        {
            q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> cnt_nodes;
    int node;
    for (int i = 0; i < cnt_nodes; ++i)
    {
        cin >> node;
        parent_idx[i] = node;
        if (node == -1)
            continue;
        tree[node].push_back(i);
    }
    cin >> erase_node;

    for (int i = 0; i < cnt_nodes; ++i)
    {
        if (tree[i].size() == 0)
            ++total_leaf_node;
    }

    bfs();

    cout << total_leaf_node;

    return 0;
}