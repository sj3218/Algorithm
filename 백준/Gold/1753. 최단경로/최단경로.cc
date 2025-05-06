
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0X7FFFFFFF

using namespace std;
int V, E;
int K;
int u, v, w;

vector<pair<int,int>> graph[20001];
int d[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> V >> E;
    cin >> K;
    fill_n(d, 20001, INF);

    for (int i = 0; i < E; ++i)
    {
        cin >> u >> v >> w;
        graph[u].push_back({ w,v });
    }

    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, K });
    d[K] = 0;

    while (!pq.empty())
    {
        int cur_d = pq.top().first;
        int cur_v = pq.top().second;
        pq.pop();

        if (d[cur_v] != cur_d)
            continue;

        for (pair<int, int> next : graph[cur_v])
        {
            if (d[next.second] <= d[cur_v] + next.first)
                continue;

            d[next.second] = d[cur_v] + next.first;
            pq.push({ d[next.second], next.second });
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (d[i] == INF)
            cout << "INF\n";
        else
            cout << d[i] << "\n";
    }
    return 0;
}