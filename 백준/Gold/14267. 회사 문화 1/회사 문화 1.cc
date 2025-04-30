#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> tree(100001);
int compliments[100001];
int answer[100001];

void bfs(int root, int w)
{
    queue<int>q;
    q.push(root);

    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        
        compliments[cur] += w;
        for (int next : tree[cur])
        {
            q.push(next);
        }
    }
}

void dfs(int root, int w)
{
    answer[root] = w + compliments[root];

    for (int next : tree[root])
    {
        dfs(next, answer[root]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    int idx;
    cin >> idx;
    for (int i = 2; i <= N; ++i)
    {
        cin >> idx;
        tree[idx].push_back(i);
    }

    int w;
    for (int i = 0; i < M; ++i)
    {
        cin >> idx >> w;
        compliments[idx] += w;
    }

    dfs(1, 0);
    for (int i = 1; i <= N; ++i)
    {
        cout << answer[i] << " ";
    }

    return 0;
}