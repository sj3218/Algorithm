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

int city_cnt, cable_cnt, power_station_cnt;
bool has_power_station[1001];
vector<tuple<int, int, int>> edges;
int parent[1001];

void Input()
{
    fill_n(parent, 1001, -1);

    cin >> city_cnt >> cable_cnt >> power_station_cnt;
    int power_station;
    for (int i = 0; i < power_station_cnt; ++i)
    {
        cin >> power_station;
        has_power_station[power_station] = true;
    }

    int u, v, w;
    for (int i = 0; i < cable_cnt; ++i)
    {
        cin >> u >> v >> w;
        edges.push_back({ w, u, v });
    }
}

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
        return false;
    if (has_power_station[x] && has_power_station[y])
        return false;

    if (has_power_station[x] || has_power_station[y])
    {
        has_power_station[x] = true;
        has_power_station[y] = true;
    }

    if (parent[x] == parent[y])
        parent[x]--;

    if (parent[x] < parent[y])
    {
        parent[y] = x;
    }
    else
        parent[x] = y;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    sort(edges.begin(), edges.end());

    int size = edges.size();
    int u, v, w;
    int cost = 0;
    for (int i = 0; i < size; ++i)
    {
        tie(w, u, v) = edges[i];
        if (Union(u, v))
        {
            cost += w;
        }
    }

    cout << cost;

    return 0;
}