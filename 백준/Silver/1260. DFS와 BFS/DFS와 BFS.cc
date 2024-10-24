#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, V;
bool is_visited[1001];
bool grid[1001][1001];

void Input()
{
    cin >> N >> M >> V;
    fill_n(is_visited, 1001, false);
    fill_n(grid[0], 1001 * 1001, false);

    int s, e;
    for (int i = 0; i < M; ++i)
    {
        cin >> s >> e;
        grid[s][e] = true;
        grid[e][s] = true;
    }
}

void dfs(int start)
{
    cout << start << " ";

    for (int i = 1; i <= N; ++i)
    {
        if (grid[start][i])
        {
            if (!is_visited[i])
            {
                is_visited[i] = true;
                dfs(i);
            }
        }
    }
}

void bfs()
{
    queue<int> q;
    q.push(V);

    fill_n(is_visited, 1001, false);
    is_visited[V] = true;

    int val;
    while (!q.empty())
    {
        val = q.front();
        q.pop();
        cout << val << " ";

        for (int i = 1; i <= N; ++i)
        {
            if (grid[val][i])
            {
                if (!is_visited[i])
                {
                    is_visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
}

int main()
{
    Input();

    is_visited[V] = true;
    dfs(V);

    cout << "\n";
    
    bfs();
    return 0;
}