#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int V, E;
int parent[10001];
pair<int, pair<int, int>> edges[100001];

int Find(int x)
{
    while (parent[x] > 0)
    {
        x = parent[x];
    }

    return x;
}

bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if (u == v)
        return false;

    if (parent[u] == parent[v])
        --parent[u];

    if (parent[u] < parent[v])
        parent[v] = u;
    else
        parent[u] = v;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(parent, 10001, -1);

    cin >> V >> E;

    int u, v, cost;
    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> cost;
        edges[i] = { cost, {u,v} };
    }

    sort(edges, edges + E);

    int cnt = 0;
    int answer = 0;

    for (int i = 0; i < E; ++i)
    {
        u = edges[i].second.first;
        v = edges[i].second.second;
        cost = edges[i].first;

        if (!Union(u, v))
            continue;

        answer += cost;
        ++cnt;
        if (cnt == V - 1)
            break;
    }

    cout << answer;
    return 0;
}