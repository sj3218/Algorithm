
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
#define INF 0x7fffffff

int barn_cnt;
int cow_road_cnt;
vector<vector<pair<int, int>>> street(50001);
int dist[50001];
bool is_visited[50001];

void Input()
{
    fill_n(dist, 50001, INF);
    cin >> barn_cnt;
    cin >> cow_road_cnt;

    int a, b, c;
    for (int i = 0; i < cow_road_cnt; ++i)
    {
        cin >> a >> b >> c;
        street[a].push_back({ b,c });
        street[b].push_back({ a,c });
    }
}

void dijkstra(int start)
{
    int curr, curr_dist;
    int next_barn, next_dist;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0,start });
    dist[start] = 0;

    while (!pq.empty())
    {
        tie(curr_dist, curr) = pq.top(); pq.pop();

        if (is_visited[curr])
            continue;

        is_visited[curr] = true;

        for (pair<int, int> next : street[curr])
        {
            tie(next_barn, next_dist) = next;

            if (is_visited[next_barn])
                continue;

            if (dist[next_barn] <= next_dist + curr_dist)
                continue;

            pq.push({ next_dist+curr_dist, next_barn });
            dist[next_barn] = next_dist + curr_dist;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    dijkstra(1);
    cout << dist[barn_cnt];

    return 0;
}