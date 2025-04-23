#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
vector<vector<int>> graph(1001);
bool is_visited[1001];

void BFS()
{
    fill_n(is_visited, 1001, false);

    queue<int> q;
    q.push(V);
    is_visited[V] = true;

    int val;
    while (!q.empty())
    {
        val = q.front();
        q.pop();
        cout << val << " ";

        for (int i = 0; i < graph[val].size(); ++i)
        {
            if (is_visited[graph[val][i]])
                continue;

            is_visited[graph[val][i]] = true;
            q.push(graph[val][i]);
        }
    }
    cout << "\n";
}

void DFS(int val)
{
    cout << val << " ";
    is_visited[val] = true;
    int size = graph[val].size();

    for (int i = 0; i < size; ++i)
    {
        if (is_visited[graph[val][i]])
            continue;

        DFS(graph[val][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> V;

    int x, y;
    for (int i = 1; i <= M; ++i)
    {
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    DFS(V);
    cout << "\n";

    BFS();

    return 0;
}