#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N;
int costs[1001][1001];
bool is_visited[1001];

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> costs[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    fill_n(is_visited, 1001, false);

    int cnt = 0;
    long long answer = 0;
    int u, v, cost;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (int i = 2; i <= N; ++i)
    {
        pq.push({ costs[1][i], 1, i });
    }
    is_visited[1] = true;

    while (cnt < N - 1)
    {
        tie(cost, u, v) = pq.top(); pq.pop();

        if (is_visited[v])
            continue;

        ++cnt;
        is_visited[v] = true;
        answer += cost;

        for (int i = 1; i <= N; ++i)
        {
            if (i == v)
                continue;
            if (is_visited[i])
                continue;
            pq.push({ costs[v][i], v, i });
        }
    }

    cout << answer;

    return 0;
}