#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;
int N, C;
vector<pair<int, pair<int, int>>> edges;
vector<pair<int, int>> fields;
int parent[2001];

int CalculateDistance(int x1, int x2, int y1, int y2)
{
    int x = x1 - x2;
    int y = y1 - y2;
    return x * x + y * y;
}

int Find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if (u > v)
        parent[u] = v;
    else if (u < v)
        parent[v] = u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> C;
    //fill_n(parent, 2001, -1);

    int x, y;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        fields.push_back({ x, y });
        parent[i] = i;
    }

    int x2, y2;
    int cnt_edges = 0;
    int dist;
    for (int i = 0; i < N; ++i)
    {
        x = fields[i].first;
        y = fields[i].second;
        for (int j = i + 1; j < N; ++j)
        {
            x2 = fields[j].first;
            y2 = fields[j].second;
            dist = CalculateDistance(x, x2, y, y2);
            if (dist < C)
                continue;
            edges.push_back({ dist, {i,j} });
        }
    }

    cnt_edges = (int)edges.size();
    sort(edges.begin(), edges.end());

    int u, v, cost;
    long long answer = 0;
    int cnt = 0;

    for (int i = 0; i < cnt_edges; ++i)
    {
        cost = edges[i].first;
        u = edges[i].second.first;
        v = edges[i].second.second;

        /*if (!Union(u, v))
            continue;*/

        if (Find(u) == Find(v))
            continue;

        Union(u, v);

        answer += cost;
        ++cnt;
        if (cnt == N - 1)
            break;
    }

    if (cnt != N - 1)
        cout << -1;
    else
        cout << answer;

    return 0;
}
