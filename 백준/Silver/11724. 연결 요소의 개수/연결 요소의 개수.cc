#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
bool is_visited[1001];
vector<vector<int>> graph(1001);

int bfs()
{
    int answer = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (is_visited[i])
            continue;

        ++answer;

        queue<int> q;
        q.push(i);
        is_visited[i] = true;

        int val;
        while (!q.empty())
        {
            val = q.front();
            q.pop();

            for (int j = 0; j < graph[val].size(); ++j)
            {
                if (is_visited[graph[val][j]])
                    continue;

                is_visited[graph[val][j]] = true;
                q.push(graph[val][j]);
            }
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    int x, y;
    for (int i = 1; i <= M; ++i)
    {
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    cout << bfs();

    return 0;
}