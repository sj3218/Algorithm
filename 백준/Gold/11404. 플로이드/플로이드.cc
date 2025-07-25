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
vector<pair<int,int>> bus_info[101];//end, cost
int cost[101];

void dijkstra(int start_city)
{
    fill_n(cost, 101, INF);

    priority_queue<int, vector<int>, greater<int>> pq;//cost, city;
    cost[start_city] = 0;
    pq.push(start_city);

    int curr_city;
    int next_city;
    int next_cost;
    while (!pq.empty())
    {
        curr_city = pq.top();
        pq.pop();
        for (pair<int, int> next : bus_info[curr_city])
        {
            tie(next_city, next_cost) = next;
            if (cost[next_city] > next_cost + cost[curr_city])
            {
                cost[next_city] = next_cost + cost[curr_city];
                pq.push(next_city);
            }
        }
    }

    for (int i = 1; i <= city_cnt; ++i)
    {
        if (cost[i] == INF)
            cout << "0 ";
        else
            cout << cost[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> city_cnt >> bus_cnt;
    int a, b, c;
    for (int i = 0; i < bus_cnt; ++i)
    {
        cin >> a >> b >> c;
        bus_info[a].push_back({ b,c });
    }

    for (int i = 1; i <= city_cnt; ++i)
    {
        dijkstra(i);
    }

    return 0;
}