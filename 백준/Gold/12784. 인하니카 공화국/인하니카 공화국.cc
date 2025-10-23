#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int T;
int N, M;
vector<vector<pair<int,int>>> tree(1001);
bool is_visited[1001];

void Input()
{
    fill_n(is_visited, 1001, false);
    tree = vector<vector<pair<int, int>>>(1001);
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        tree[a].push_back({ b,c });
        tree[b].push_back({ a,c });
    }
}

int dfs(int curr)
{
    int answer = 0;
    int node, cnt;
    int temp;
    for (pair<int, int> next : tree[curr])
    {
        tie(node, cnt) = next;
        if (is_visited[node])
            continue;
        
        is_visited[node] = true;
        temp = dfs(node);
        
        if (temp == 0 || cnt < temp)
            answer += cnt;
        else
            answer += temp;
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        Input();
        is_visited[1] = true;
        cout << dfs(1) << "\n";
    }

    return 0;
}