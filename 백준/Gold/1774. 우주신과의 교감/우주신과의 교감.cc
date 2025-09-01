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

int god_cnt, already_connected_cnt;
pair<int, int> positions[1001];
int parent[1001];

int Find(int x)
{
    while (parent[x] > 0)
    {
        x = parent[x];
    }
    return x;
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y)
    {
        return false;
    }

    if (parent[x] == parent[y])
        --parent[x];

    if (parent[x] < parent[y])
        parent[y] = x;
    else
        parent[x] = y;

    return true;
}

void Input()
{
    fill_n(parent, 1001, -1);

    cin >> god_cnt >> already_connected_cnt;

    int x, y;
    for (int i = 1; i <= god_cnt; ++i)
    {
        cin >> x >> y;
        positions[i] = { x, y };
    }

    for (int i = 1; i <= already_connected_cnt; ++i)
    {
        cin >> x >> y;
        Union(x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    vector<tuple<double, int, int>> edges;
    double cost;
    int x1, y1;
    int x2, y2;
    for (int i = 1; i <= god_cnt; ++i)
    {
        tie(x1, y1) = positions[i];
        for (int j = i + 1; j <= god_cnt; ++j)
        {
            tie(x2, y2) = positions[j];
            cost = pow((x2 - x1),2) + pow((y2 - y1),2);
            //cost = sqrt(cost);
            edges.push_back({ cost, i, j });
        }
    }

    sort(edges.begin(), edges.end());
    int size = edges.size();
    int x, y;
    double total_cost = 0.f;
    int cnt = already_connected_cnt;
    for (int i = 0; i < size; ++i)
    {
        tie(cost, x, y) = edges[i];

        if (Union(x, y))
        {
            cost = sqrt(cost);
            total_cost += cost;
            ++cnt;
        }

    }

    cout << fixed << setprecision(2) << total_cost;
    return 0;
}