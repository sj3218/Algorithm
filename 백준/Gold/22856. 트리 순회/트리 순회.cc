#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> tree(100001);
int total_count;
bool is_visited[100001];
int end_node;

void FindEndNode()
{
    int node = 1;
    while (true)
    {
        if (tree[node].second == -1)
        {
            end_node = node;
            break;
        }

        node = tree[node].second;
    }
}

bool dfs(int curr)
{
    is_visited[curr] = true;
    int left_node = tree[curr].first;
    int right_node = tree[curr].second;

    if (left_node != -1 && !is_visited[left_node])
    {
        ++total_count;
        if (dfs(left_node))
            return true;
    }

    if (right_node != -1 && !is_visited[right_node])
    {
        ++total_count;
        if (dfs(right_node))
            return true;
    }

    if (curr == end_node)
    {
        return true;
    }

    ++total_count;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int curr, left, right;
    for (int i = 1; i <= N; ++i)
    {
        cin >> curr >> left >> right;
        tree[curr] = { left, right };
    }

    FindEndNode();
    dfs(1);
    cout << total_count;

    return 0;
}