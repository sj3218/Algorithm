#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 0X7FFFFFFFFFFFFFFF
#define MAX_CITY 100001

using namespace std;

int N, M, K;
int u, v, k;
long long c;

vector<vector<pair<int,long long>>> city(MAX_CITY);
long long dist[MAX_CITY];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

void dijkstra()
{
    int curr, nx_city;
    long long curr_w, nx_w;

    while (!pq.empty())
    {
        curr_w = pq.top().first;
        curr = pq.top().second;
        pq.pop();

        if (dist[curr] < curr_w)
            continue;

        for (pair<int, long long> next : city[curr])
        {
            nx_city = next.first;
            nx_w = next.second;

            nx_w += dist[curr];
            if (dist[nx_city] <= nx_w)
                continue;

            dist[nx_city] = nx_w;
            pq.push({ nx_w, nx_city });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(dist, MAX_CITY, INF);

    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i)
    {
        cin >> u >> v >> c;
        city[v].push_back({ u,c });
    }

    for (int i = 0; i < K; ++i)
    {
        cin >> k;
        dist[k] = 0;
        pq.push({ 0, k });
    }

    long long max_dist = 0;
    int max_idx = 0;

    dijkstra();

    max_idx = max_element(dist + 1, dist + N + 1) - dist;
    max_dist = dist[max_idx];

    cout << max_idx << "\n" << max_dist;
    return 0;
}