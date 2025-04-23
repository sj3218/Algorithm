#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int cnt_computers;
int cnt_connections;
vector<vector<int>> network(101);
bool is_visited[101];

int bfs()
{
    int answer = 0;

    queue<int> q;
    q.push(1);
    is_visited[1] = true;

    int val = 0;
    int size = 0;
    while (!q.empty())
    {
        val = q.front();
        q.pop();

        size = network[val].size();

        for (int i = 0; i < size; ++i)
        {
            if (is_visited[network[val][i]])
                continue;

            is_visited[network[val][i]] = true;
            q.push(network[val][i]);
            ++answer;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> cnt_computers >> cnt_connections;

    int x, y;
    for (int i = 0; i < cnt_connections; ++i)
    {
        cin >> x >> y;

        network[x].push_back(y);
        network[y].push_back(x);
    }

    cout << bfs();

    return 0;
}