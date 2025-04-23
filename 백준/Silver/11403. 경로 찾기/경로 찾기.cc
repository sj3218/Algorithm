#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int>> graph(101);
int answer[101][101];

void print_graph()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}

void bfs(int val)
{
    bool is_visited[101];
    fill_n(is_visited, 101, false);

    queue<int> q;
    q.push(val);
    //is_visited[val] = true;

    int num;
    while (!q.empty())
    {
        num = q.front();
        q.pop();

        for (int i = 0; i < graph[num].size(); ++i)
        {
            if (is_visited[graph[num][i]])
                continue;

            is_visited[graph[num][i]] = true;
            q.push(graph[num][i]);
            answer[val][graph[num][i]] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int num;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> num;
            if (num == 1)
            {
                graph[i].push_back(j);
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        bfs(i);
    }

    print_graph();

    return 0;
}