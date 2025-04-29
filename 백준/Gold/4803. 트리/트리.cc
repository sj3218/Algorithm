#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int T;
vector<vector<int>> tree(501);
bool is_visited[501];
int is_parent[501];

void bfs(int idx)
{
    if (is_visited[idx] == true)
        return;

    queue<int> q;
    q.push(idx);
    is_parent[idx] = 0;
    is_visited[idx] = true;

    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        for (int next : tree[cur])
        {
            if (is_parent[cur] == next)
                continue;

            if (is_visited[next] == true)
            {
                return;
            }

            is_parent[next] = cur;
            is_visited[next] = true;
            q.push(next);
        }
    }

    ++T;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test_case = 0;
    while (++test_case)
    {
        T = 0;
        cin >> N >> M;

        if (N == 0 && M == 0)
            break;

        fill(tree.begin(), tree.end(), vector<int>());
        fill_n(is_visited, 501, false);
        fill_n(is_parent, 501, -1);

        int l, r;
        for (int i = 0; i < M; ++i)
        {
            cin >> l >> r;
            tree[l].push_back(r);
            tree[r].push_back(l);
        }

        for (int i = 1; i <= N; ++i)
        {
            bfs(i);
        }

        if (T == 0)
        {
            cout << "Case " << test_case << ": No trees.\n";
        }
        else if (T == 1)
        {
            cout << "Case " << test_case << ": There is one tree.\n";
        }
        else
        {
            cout << "Case " << test_case << ": A forest of " <<T <<" trees.\n";
        }

    }
    return 0;
}