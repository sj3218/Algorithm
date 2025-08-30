#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N;
int cost[1001][1001];
vector<tuple<int, int, int>> edges;
int parent[1001];

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> cost[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            edges.push_back({ cost[i][j], i, j });
        }
    }
}

int find_(int x)
{
    while (parent[x] > 0)
    {
        x = parent[x];
    }
    return x;
}

bool union_(int u, int v)
{
    u = find_(u);
    v = find_(v);

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

    Input();
    fill_n(parent, 1001, -1);
    sort(edges.begin(), edges.end());

    int cnt = 0;
    long long answer = 0;
    int edge_size = edges.size();
    int u, v, cost;

    for (int i = 0; i < edge_size; ++i)
    {
        tie(cost, u, v) = edges[i];

        if (!union_(u, v))
            continue;

        answer += cost;
        ++cnt;
        if (cnt == N - 1)
            break;
    }

    cout << answer;

    return 0;
}