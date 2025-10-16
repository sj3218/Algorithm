
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
#define MAX_VALUE 17
using namespace std;

int N, M;
vector<vector<int>> pairs(100001);
vector<vector<int>> trees(100001);
int depth[100001];
int parent[100001][18];

void Input()
{
    cin >> N;
    fill_n(depth, 100001, -1);
    int a, b;
    for (int i = 0; i < N-1; ++i)
    {
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    depth[1] = 0;
    int curr;
    while (!q.empty())
    {
        curr = q.front(); q.pop();

        for (int i : pairs[curr])
        {
            if (depth[i] != -1)
                continue;

            trees[curr].push_back(i);
            depth[i] = depth[curr] + 1;
            parent[i][0] = curr;
            q.push(i);
        }
    }
}

int FindNearAncestor(int a, int b)
{
    int depth_a = depth[a];
    int depth_b = depth[b];

    if (depth_a > depth_b)
    {
        swap(depth_a, depth_b);
        swap(a, b);
    }

    int diff = depth_b - depth_a;
    for (int i = 0; diff != 0; ++i)
    {
        if (diff % 2)
            b = parent[b][i];
        diff /= 2;
    }

    if (a != b)
    {
        for (int i = MAX_VALUE; i >= 0; --i)
        {
            if (parent[a][i] != 0 && parent[a][i] != parent[b][i])
            {
                a = parent[a][i];
                b = parent[b][i];
            }
        }

        return parent[a][0];
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

void Connect()
{
    for (int k = 1; k <= MAX_VALUE; ++k)
    {
        for (int curr = 1; curr <= N; ++curr)
        {
            parent[curr][k] = parent[parent[curr][k - 1]][k - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Connect();
    Solution();

    return 0;
}