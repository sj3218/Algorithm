#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int N, M;
vector<vector<int>> graph(20001);
int is_visited[20001];

void bfs()
{
    queue<int> q;
    q.push(1);
    is_visited[1] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr])
        {
            if (is_visited[next] != -1)
                continue;

            is_visited[next] = is_visited[curr] + 1;
            q.push(next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    fill_n(is_visited, 20001, -1);
    bfs();

    int answer;
    int distance = 0;
    int cnt;

    for (int i = 2; i <= N; ++i)
    {
        if (is_visited[i] > distance)
        {
            answer = i;
            distance = is_visited[i];
            cnt = 1;
        }
        else if (is_visited[i] == distance)
        {
            ++cnt;
        }
    }

    cout << answer << " " << distance << " " << cnt;
    return 0;
}