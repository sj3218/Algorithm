#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int cnt_know_person;
bool num_know_person[51];

vector<vector<int>> graph(51);
vector<vector<int>> party(51);

int answer = 0;

bool bfs(int idx_party)
{
    queue<int> q;
    q.push(party[idx_party][0]);
    int idx;

    bool is_visited[51];
    fill_n(is_visited, 51, false);
    is_visited[party[idx_party][0]] = true;

    int size;
    while (!q.empty())
    {
        idx = q.front();
        q.pop();

        if (num_know_person[idx])
            return false;

        size = graph[idx].size();
        for (int i = 0; i < size; ++i)
        {
            if (is_visited[graph[idx][i]])
                continue;
            if (num_know_person[graph[idx][i]])
                return false;

            is_visited[graph[idx][i]] = true;
            q.push(graph[idx][i]);
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cin >> cnt_know_person;
    int idx;
    for (int i = 1; i <= cnt_know_person; ++i)
    {
        cin >> idx;
        num_know_person[idx] = true;
    }

    int prev, next;
    for (int i = 0; i < M; ++i)
    {
        cin >> idx;
        cin >> prev;
        party[i].push_back(prev);
        for (int j = 1; j < idx; ++j)
        {
            cin >> next;
            party[i].push_back(next);
            graph[prev].push_back(next);
            graph[next].push_back(prev);
            prev = next;
        }
    }

    for (int i = 0; i < M; ++i)
    {
        if (bfs(i))
            ++answer;
    }

    cout << answer;
    return 0;
}