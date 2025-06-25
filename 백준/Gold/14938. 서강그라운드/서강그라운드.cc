#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
#define INF 0X7FFFFFFF

int area, range, cnt_path;
int items[101];
vector<vector<pair<int,int>>> graph(101); // area, length
int dist[101];

int dijkstra(int start)
{
    fill_n(dist, 101, INF);
    int sum = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, start });
    dist[start] = 0;

    int curr_length, curr_area;
    while (!pq.empty())
    {
        tie(curr_length, curr_area) = pq.top();
        pq.pop();

        for (pair<int, int> next : graph[curr_area])
        {
            if (dist[curr_area] + next.second > range)
                continue;

            if (dist[curr_area] + next.second >= dist[next.first])
                continue;

            dist[next.first] = dist[curr_area] + next.second;
            pq.push({ dist[next.first], next.first });
        }
    }

    for (int i = 1; i <= area; ++i)
    {
        if (dist[i] == INF)
            continue;
        sum += items[i];
    }
    
    return sum;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> area >> range >> cnt_path;
    for (int i = 1; i <= area; ++i)
    {
        cin >> items[i];
    }

    int a, b, l;
    for (int i = 0; i < cnt_path; ++i)
    {
        cin >> a >> b >> l;
        graph[a].push_back({ b,l });
        graph[b].push_back({ a,l });
    }

    int answer = -1;
    for (int i = 1; i <= area; ++i)
    {
        answer = max(answer, dijkstra(i));
    }

    cout << answer;

    return 0;
}
