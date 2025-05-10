#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0X7FFFFFFF

using namespace std;

int N, E;
int a, b, c;
int v1, v2;
int answer = -1;

vector<vector<pair<int, int>>> graph(801);
int dist_1[801];
int dist_v1[801];
int dist_v2[801];

void dijkstra(int start, int* dist)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    int curr_w, curr_node;
    while (!pq.empty())
    {
        curr_w = pq.top().first;
        curr_node = pq.top().second;
        pq.pop();

        if (dist[curr_node] < curr_w)
            continue;

        int nx_w, nx_node;
        for (pair<int, int> next : graph[curr_node])
        {
            nx_node = next.first;
            nx_w = next.second;

            if (dist[nx_node] <= nx_w + dist[curr_node])
            {
                continue;
            }

            dist[nx_node] = nx_w + dist[curr_node];
            pq.push({ dist[nx_node], nx_node });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> E;

    for (int i = 0; i < E; ++i)
    {
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }

    cin >> v1 >> v2;

    fill_n(dist_1, 801, INF);
    fill_n(dist_v1, 801, INF);
    fill_n(dist_v2, 801, INF);

    dijkstra(1, dist_1);
    dijkstra(v1, dist_v1);
    dijkstra(v2, dist_v2);

    int path_1 = dist_1[v1] + dist_v1[v2] + dist_v2[N];
    int path_2 = dist_1[v2] + dist_v2[v1] + dist_v1[N];

    if (dist_1[v1] == INF || dist_v1[v2] == INF || dist_v2[N] == INF)
        path_1 = INF;

    if (dist_1[v2] == INF || dist_v2[v1] == INF || dist_v1[N] == INF)
        path_2 = INF;

    answer = min(path_1, path_2);
    if (answer == INF)
        cout << -1;
    else
        cout << answer;
    return 0;
}