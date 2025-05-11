#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0X7FFFFFFF

using namespace std;
int N, M, X;
vector<vector<pair<int, int>>> town(1001);
int dist_goal[1001];
int dist_home[1001];
int max_dist = 0;

void dijkstra(int start, int* dist)
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ 0,start });

    dist[start] = 0;

    int curr_pos, curr_w;
    while (!pq.empty())
    {
        curr_pos = pq.top().second;
        curr_w = pq.top().first;
        pq.pop();

        if (dist[curr_pos] < curr_w)
            continue;

        int nx_pos, nx_w;
        for (pair<int, int> next : town[curr_pos])
        {
            nx_pos = next.first;
            nx_w = next.second;

            if (dist[nx_pos] <= nx_w + dist[curr_pos])
                continue;

            dist[nx_pos] = nx_w + dist[curr_pos];
            pq.push({ dist[nx_pos], nx_pos });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(dist_goal, 1001, INF);
    fill_n(dist_home, 1001, INF);

    int s, e, w;
    cin >> N >> M >> X;

    for (int i = 0; i < M; ++i)
    {
        cin >> s >> e >> w;
        town[s].push_back({ e,w });
    }

    dijkstra(X, dist_home);
    int temp;

    for (int i = 1; i <= N; ++i)
    {
        if (i == X)
            continue;

        fill_n(dist_goal, 1001, INF);
        dijkstra(i, dist_goal);

        temp = dist_goal[X] + dist_home[i];
        if (temp > max_dist)
        {
            max_dist = temp;
        }
    }

    cout << max_dist;
    return 0;
}