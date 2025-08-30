#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int house_cnt;
int street_cnt;
vector<tuple<int, int, int>> edges;
int parent[100001];

int Find(int x)
{
    while (parent[x] > 0)
        x = parent[x];
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

    cin >> house_cnt >> street_cnt;
    if (house_cnt == 2)
    {
        cout << 0;
        return 0;
    }

    int u, v, cost;
    for (int i = 0; i < street_cnt; ++i)
    {
        cin >> u >> v >> cost;
        edges.push_back({ cost, u, v });
    }

    sort(edges.begin(), edges.end());

    int size = edges.size();
    int cnt = 0;
    long long answer = 0;
    for (int i = 0; i < size; ++i)
    {
        tie(cost, u, v) = edges[i];
        if (Union(u, v))
        {
            ++cnt;
            answer += cost;
        }

        if (cnt == house_cnt - 2)
            break;
    }

    cout << answer;

    return 0;
}