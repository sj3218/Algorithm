#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int K;
int V, E;
vector<vector<int>> graph(20001);
int is_visited[20001];

bool bfs(int idx)
{
    queue<int> q;
    q.push(idx);
    is_visited[idx] = 1;

    while (!q.empty())
    {
        int cur = q.front();
        int bi = is_visited[cur];
        q.pop();

        for (int next : graph[cur])
        {
            if (is_visited[next] != 0)
            {
                if (is_visited[next] != -bi)
                    return false;
                continue;
            }

            is_visited[next] = -bi;
            q.push(next);
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> K;

    int u, v;
    while (K--)
    {
        bool answer = true;

        cin >> V >> E;
        fill(graph.begin(), graph.begin() + V + 1, vector<int>());
        fill_n(is_visited, V + 1, 0);

        for (int i = 0; i < E; ++i)
        {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 1; i <= V; ++i)
        {
            if (is_visited[i] != 0)
                continue;

            if (!bfs(i))
            {
                answer = false;
                break;
            }
        }

        if (answer)
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }

    return 0;
}