#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

vector<pair<int, int>> bus_info[501];
int city_cnt, bus_cnt;
int a, b, c;

long long cost[501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(cost, 501, INF);
    cin >> city_cnt >> bus_cnt;
    for (int i = 0; i < bus_cnt; ++i)
    {
        cin >> a >> b >> c;
        bus_info[a].push_back({ b,c });
    }

    cost[1] = 0;
    for (int i = 0; i < city_cnt; ++i)
    {
        for (int j = 1; j <= city_cnt; ++j)
        {
            for (pair<int, int> bus : bus_info[j])
            {
                int next_pos = bus.first;
                int c = bus.second;

                if (cost[j] == INF)
                    continue;
                if (cost[next_pos] <= cost[j] + c)
                    continue;

                cost[next_pos] = cost[j] + c;

                if (i == city_cnt - 1)
                {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    for (int i = 2; i <= city_cnt; ++i)
    {
        if (cost[i] == INF)
            cout << "-1\n";
        else
            cout << cost[i] <<"\n";
    }

    return 0;
}