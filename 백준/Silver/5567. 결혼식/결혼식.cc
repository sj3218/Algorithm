#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX_FRIENDS 2

using namespace std;

int N, M;
vector<vector<int>> graph(501);
bool is_visited[501];

int bfs()
{
    int answer = 0;
    queue<pair<int, int>> q; // val, cnt

    q.push({ 1,0 });
    is_visited[1] = true;

    int val, cnt, size;
    while (!q.empty())
    {
        val = q.front().first;
        cnt = q.front().second;

        q.pop();

        if (cnt == MAX_FRIENDS)
            continue;

        size = graph[val].size();
        for (int i = 0; i < size; ++i)
        {
            if (is_visited[graph[val][i]])
                continue;

            is_visited[graph[val][i]] = true;
            q.push({graph[val][i], cnt + 1});
            ++answer;
        }
    }

    return answer;
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

    cout << bfs();

    return 0;
}