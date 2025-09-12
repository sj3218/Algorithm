#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
#define INF 0X7FFFFFFF

int test_case_cnt;
int node_cnt;
vector<vector<int>> trees(10001);
int node_a, node_b;
int parent[10001];
bool has_a[10001];
bool has_b[10001];
int head;
int answer = 0;

int FindParent(int a)
{
    while (parent[a] > 0)
        a = parent[a];
    return a;
}
void Input()
{
    cin >> node_cnt;
    trees.assign(10001, {});
    fill_n(parent, 10001, -1);
    fill_n(has_a, 10001, false);
    fill_n(has_b, 10001, false);
    head = 0;
    int head_depth = 0;

    int a, b;
    for (int i = 1; i < node_cnt; ++i)
    {
        cin >> a >> b;
        trees[a].push_back(b);

        int parent_idx = FindParent(a);
        if (parent[b] == -1)
        {
            parent[parent_idx]--;
        }
        else
        {
            if (parent[parent_idx] >= parent[b])
            {
                parent[parent_idx] += parent[b];
            }
        }

        parent[b] = a;
        if (head_depth > parent[parent_idx])
        {
            head_depth = parent[parent_idx];
            head = parent_idx;
        }
    }

    cin >> node_a >> node_b;

    answer = head;
    
}

bool dfs(int curr_node, int find_node, bool has_node[])
{
    for (int next : trees[curr_node])
    {
        if (next == find_node)
        {
            has_node[curr_node] = true;
            has_node[next] = true;
            return true;
        }

        if (dfs(next, find_node, has_node))
        {
            has_node[curr_node] = true;
            return true;
        }
    }

    return false;
}

void FindNearAncestor(int curr_node)
{
    int temp = -1;

    if (has_a[curr_node] && has_b[curr_node])
    {
        answer = curr_node;
        for (int next : trees[curr_node])
        {
            FindNearAncestor(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> test_case_cnt;
    while (test_case_cnt--)
    {
        Input();
        dfs(head, node_a, has_a);
        dfs(head, node_b, has_b);
        FindNearAncestor(head);
        cout << answer <<"\n";
    }

    return 0;
}