#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, A, B;
long long C;
vector<vector<pair<int, int>>> graph;

bool canGo(int maxToll) {
    vector<long long> cost(N + 1, 1e18);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

    cost[A] = 0;
    pq.push({ 0, A });

    while (!pq.empty()) {
        long long curCost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (curCost > cost[u]) continue;

        for (pair<int,int> next : graph[u]) {
            int v = next.first;
            int toll = next.second;
            if (toll > maxToll) continue;

            long long newCost = curCost + toll;
            if (newCost < cost[v]) {
                cost[v] = newCost;
                pq.push({ newCost, v });
            }
        }
    }

    return cost[B] <= C;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M >> A >> B >> C;

    graph.resize(N + 1);
    int u, v, w;
    int maxEdge = 0;
    for (int i = 0; i < M; ++i) {
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
        maxEdge = max(maxEdge, w);
    }

    int lo = 0, hi = maxEdge;
    int answer = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (canGo(mid)) {
            answer = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }

    cout << answer << '\n';
}
