#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int city_cnt;
int bus_cnt;
vector<tuple<int, int, int>> bus_info;
long long cost[501];

bool bellman_ford(int start)
{
    cost[start] = 0;
    int a, b, c;
    for (int i = 1; i <= city_cnt - 1; ++i)
    {
        for (tuple<int, int, int> info : bus_info)
        {
            tie(a, b, c) = info;
            if (cost[a] == INF)
                continue;
            if (cost[b] <= cost[a] + c)
                continue;

            cost[b] = cost[a] + c;
        }
    }

    for (tuple<int, int, int> info : bus_info)
    {
        tie(a, b, c) = info;
        if (cost[a] != INF && cost[b] > cost[a] + c)
            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> city_cnt >> bus_cnt;

    int A, B, C;
    for (int i = 0; i < bus_cnt; ++i)
    {
        cin >> A >> B >> C;
        bus_info.push_back({ A,B,C });
    }

    fill_n(cost, 501, INF);
    if (bellman_ford(1))
    {
        for (int i = 2; i <= city_cnt; ++i)
        {
            if (cost[i] == INF)
                cout << "-1\n";
            else
                cout << cost[i] << "\n";
        }
    }
    else
        cout << -1;

    return 0;
}