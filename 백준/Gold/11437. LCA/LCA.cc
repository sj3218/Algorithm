
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int N, M;
vector<vector<int>> pairs(50001);
vector<vector<int>> trees(50001);
pair<int,int> node_info[50001]; //depth, parent node

void Input()
{
    cin >> N;

    int a, b;
    for (int i = 0; i < N-1; ++i)
    {
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    fill_n(node_info, 50001, make_pair(INF,INF));
    queue<int> q;
    q.push(1);
    node_info[1] = { 0, -1 };
    int curr;
    while (!q.empty())
    {
        curr = q.front(); q.pop();

        for (int i : pairs[curr])
        {
            if (node_info[i].first != INF)
                continue;
            trees[curr].push_back(i);
            node_info[i] = { node_info[curr].first + 1, curr };
            q.push(i);
        }
    }
}

int FindNearAncestor(int a, int b)
{
    int depth_a = node_info[a].first;
    int depth_b = node_info[b].first;

    if (depth_a > depth_b)
    {
        swap(a, b);
        swap(depth_a, depth_b);
    }

    int size = depth_b - depth_a;
    for (int i = 0; i < size; ++i)
    {
        b = node_info[b].second;
    }

    while (a != b)
    {
        a = node_info[a].second;
        b = node_info[b].second;
    }

    return a;
}

void Solution()
{
    cin >> M;
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        cout << FindNearAncestor(a, b) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();

    return 0;
}