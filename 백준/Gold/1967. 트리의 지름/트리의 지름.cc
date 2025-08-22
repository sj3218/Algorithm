#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N;
vector<vector<pair<int, int>>> graph(10001);
bool is_visited[10001];
int answer = 0;
int dist[10001];

void dfs(int node)
{
    int nx, cost;
    int _max = 0;
    priority_queue<int> pq;
    for (pair<int, int> next : graph[node])
    {
        tie(nx, cost) = next;
        if (is_visited[nx])
            continue;

        is_visited[nx] = true;
        dfs(nx);
        pq.push(cost + dist[nx]);
        _max = max(_max, cost+dist[nx]);
    }

    dist[node] = _max;

    //leaf
    if (pq.empty())
        return;

    int sum = pq.top(); pq.pop();
    if (!pq.empty())
        sum += pq.top();

    answer = max(answer, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    int parent, child, cost;
    for (int i = 1; i < N; ++i)
    {
        cin >> parent >> child >> cost;
        graph[parent].push_back({ child,cost });
        graph[child].push_back({ parent,cost });
    }

    is_visited[1] = true;
    dfs(1);
    cout << answer;
    return 0;
}