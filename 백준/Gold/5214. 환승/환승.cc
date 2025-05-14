#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int N, K, M;
vector<vector<int>> graph(100001);
vector<vector<int>> hypertube(1001);
int is_visited[100001];

void bfs()
{
    queue<int> q;
    q.push(1);
    is_visited[1] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int hyper : graph[curr])
        {
            for (int next : hypertube[hyper])
            {
                if (is_visited[next] != -1)
                    continue;

                is_visited[next] = is_visited[curr] + 1;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K >> M;

    int c;
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 0; j < K; ++j)
        {
            cin >> c;
            graph[c].push_back(i);
            hypertube[i].push_back(c);
        }
    }

    fill_n(is_visited, 100001, -1);

    bfs();

    cout << is_visited[N];

    return 0;
}