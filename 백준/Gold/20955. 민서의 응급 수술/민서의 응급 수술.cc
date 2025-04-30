#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int u, v;
vector<vector<int>> tree(100001);
bool is_visited[100001];
int answer = 0;

void dfs(int root)
{
    if (is_visited[root] == true)
        return;
    is_visited[root] = true;

    for (int next : tree[root])
    {
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        if (is_visited[i] == true)
            continue;

        dfs(i);
        ++answer;
    }

    cout << (answer - 1) + (M + answer - 1 - (N-1)); // answer - 1:     answer는 트리의 개수. answer-1만큼 간선 추가해서 연결시켜야함. 
                                                    //  M + answer - 1: 지금 총 간선 개수. 
                                                    //  N-1:            하나의 트리의 간선 개수는 N-1이기 때문에 지금 총 간선 개수에서 N-1을 빼줘야 얼만큼 빼야하는 지 알수 있음
    return 0;
}
