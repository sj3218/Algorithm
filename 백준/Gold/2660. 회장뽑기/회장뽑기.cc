#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 0X7FFFFFFF

using namespace std;
int N;
vector<vector<int>> graph(51);
int is_visited[51][51];
int scores[51];
int min_score = INF;

void bfs(int cur)
{
    int score = 0;
    queue<int> q;
    q.push(cur);
    is_visited[cur][cur] = 0;

    int size;
    int x;
    int idx;
    while (!q.empty())
    {
        x = q.front();
        q.pop();

        size = graph[x].size();
        for (int i = 0; i < size; ++i)
        {
            idx = graph[x][i];
            if (is_visited[cur][idx] != -1)
                continue;

            is_visited[cur][idx] = is_visited[cur][x] + 1;
            q.push(idx);

            score = max(score, is_visited[cur][idx]);
        }
    }

    scores[cur] = score;
    min_score = min(min_score, scores[cur]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(is_visited[0], 51 * 51, -1);

    cin >> N;
    int x=0, y=0;
    while (true)
    {
        cin >> x >> y;
        if (x == -1 && y == -1)
            break;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i = 1; i <= N; ++i)
    {
        bfs(i);
    }

    vector<int> presidents;
    for (int i = 1; i <= N; ++i)
    {
        if (min_score == scores[i])
        {
            presidents.push_back(i);
        }
    }

    cout << min_score << " " << presidents.size() <<"\n";
    for (int i = 0; i < presidents.size(); ++i)
    {
        cout << presidents[i] << " ";
    }


    return 0;
}