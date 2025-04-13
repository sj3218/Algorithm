#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, Q;
//int graph[5001][5001];
vector<vector<pair<int,int>>> graph(5001, vector<pair<int,int>>()); // graph[p] -> {q, r}

bool is_visited[5001];

int bfs(int k, int v)
{
    fill_n(is_visited, 5001, false);
    queue<int> q;
    q.push(v);
    is_visited[v] = true;
    int answer = 0;
    while (!q.empty())
    {
        int video = q.front();
        q.pop();

        int size = graph[video].size();
        for (int i = 0; i < size; ++i)
        {
            int n_video = graph[video][i].first;
            int value = graph[video][i].second;

            if (is_visited[n_video] != 0)
            {
                continue;
            }

            if (value >= k)
            {
                ++answer;
                is_visited[n_video] = true;
                q.push(n_video);
            }
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    int p, q, r;
    int k, v;

    for (int i = 0; i < N - 1; ++i)
    {
        cin >> p >> q >> r;
        graph[p].push_back({ q,r });
        graph[q].push_back({ p,r });
        /*graph[q][p] = r;
        graph[p][q] = r;*/
    }

    for (int i = 0; i < Q; ++i)
    {
        cin >> k >> v;
        cout << bfs(k, v) << "\n";
    }

    return 0;
}