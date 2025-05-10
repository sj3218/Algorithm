#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0X7FFFFFFF

using namespace std;
int N, M;
int start_city, end_city;
vector < vector<pair<int, int>>> graph(1001);
int dist[1001];

void dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[start_city] = 0;
    pq.push({ 0, start_city });

    int curr_city, curr_w;
    while (!pq.empty())
    {
        curr_w = pq.top().first;
        curr_city = pq.top().second;
        pq.pop();

        if (dist[curr_city] < curr_w)
            continue;

        for (pair<int, int> next : graph[curr_city])
        {
            int nx_city = next.first;
            int nx_w = next.second;

            if (dist[nx_city] <= nx_w + dist[curr_city])
            {
                continue;
            }

            dist[nx_city] = nx_w + dist[curr_city];
            pq.push({ dist[nx_city], nx_city });
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int s, e, w;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> s >> e >> w;
        graph[s].push_back({ e,w });
    }

    cin >> start_city >> end_city;
    fill_n(dist, 1001, INF);

    dijkstra();
    cout << dist[end_city];

    return 0;
}