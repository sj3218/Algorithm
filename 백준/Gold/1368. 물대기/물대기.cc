#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
int parent[301];
pair<int, pair<int, int>> edges[100001];
int cnt = 0;

int Find(int idx)
{
    int x = idx;
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
    {
        return false;
    }

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
    
    cin >> N;
    
    fill_n(parent, 301, -1);

    int cost;
    for (int i = 1; i <= N; ++i)
    {
        cin >> cost;
        edges[cnt] = { cost, {i, 0} };
        ++cnt;
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> cost;
            if (i >= j)
                continue;

            edges[cnt] = { cost, {i, j} };
            ++cnt;
        }
    }

    ++N;
    sort(edges, edges + cnt);

    int u, v;
    int cur_cnt = 0;
    int answer = 0;
    for (int i = 0; i < cnt; ++i)
    {
        u = edges[i].second.first;
        v = edges[i].second.second;
        cost = edges[i].first;

        if (!Union(u, v))
            continue;

        answer += cost;
        ++cur_cnt;

        if (cur_cnt == N - 1)
            break;
    }

    cout << answer;
    return 0;
}