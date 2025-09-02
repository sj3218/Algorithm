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

int building_cnt, street_cnt;
vector<pair<int, int>> edges[1001];
bool is_visited[1001];

void Input()
{
    cin >> building_cnt >> street_cnt;
    int a, b, c;
    for (int i = 0; i <= street_cnt; ++i)
    {
        cin >> a >> b >> c;
        edges[a].push_back({ b, c });
        edges[b].push_back({ a, c });
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    priority_queue<tuple<int, int, int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq_greater;
    priority_queue<tuple<int, int, int>> pq_less;
    int cost, a, b;
    for (pair<int, int> next : edges[0])
    {
        tie(b, cost) = next;
        pq_greater.push({ cost, 0, b });
        pq_less.push({ cost, 0, b });
    }

    int cnt = 0;
    int max_cost = 0;
    int min_cost = 0;

    //greater
    fill_n(is_visited, 1001, false);
    is_visited[0] = true;
    while (cnt < building_cnt)
    {
        tie(cost, a, b) = pq_greater.top(); pq_greater.pop();

        if (is_visited[b])
            continue;
        is_visited[b] = true;
        ++cnt;

        if (cost == 0)
            ++max_cost;

        for (pair<int, int> next : edges[b])
        {
            if (is_visited[next.first])
                continue;

            pq_greater.push({ next.second, b, next.first });
        }
    }

    //less
    fill_n(is_visited, 1001, false);
    is_visited[0] = true;
    cnt = 0;
    while (cnt < building_cnt)
    {
        tie(cost, a, b) = pq_less.top(); pq_less.pop();

        if (is_visited[b])
            continue;

        if (cost == 0)
            ++min_cost;
        is_visited[b] = true;
        ++cnt;

        for (pair<int, int> next : edges[b])
        {
            if (is_visited[next.first])
                continue;

            pq_less.push({ next.second, b, next.first });
        }
    }

    cout << pow(max_cost, 2) - pow(min_cost, 2);
    return 0;
}