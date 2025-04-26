#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M;
vector<vector<int>> light(100);
vector<vector<int>> heavy(100);
bool is_visited[100];
int mid_value;

bool bfs(int idx, vector<vector<int>> adj)
{
    fill_n(is_visited, 100, false);
    is_visited[idx] = true;
    queue<int> q;
    q.push(idx);

    int cur, next;
    int cnt = 0;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); ++i)
        {
            next = adj[cur][i];
            if (is_visited[next])
                continue;

            ++cnt;
            q.push(next);
            is_visited[next] = true;
        }
    }

    if (cnt >= mid_value)
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    mid_value = (N + 1) / 2;

    int h, l;
    for (int i = 0; i < M; ++i)
    {
        cin >> h >> l;
        light[h].push_back(l); //light -> h > l
        heavy[l].push_back(h); // heavy -> l < h
    }

    int answer = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (bfs(i, light) || bfs(i, heavy))
            ++answer;
    }
    cout << answer;
    return 0;
}