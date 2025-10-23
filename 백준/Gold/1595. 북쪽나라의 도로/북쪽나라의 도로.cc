#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

vector<pair<int,int>> tree[10001]; //node, dist
bool is_visited[10001];
int far_node;
int answer = 0;

void Input()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        tree[a].push_back({ b,c });
        tree[b].push_back({ a,c });
    }
}

void dfs(int curr, int dist)
{
    if (answer < dist)
    {
        answer = dist;
        far_node = curr;
    }

    int node;
    int d;
    for (pair<int,int> next : tree[curr])
    {
        tie(node, d) = next;
        if (is_visited[node])
            continue;
        is_visited[node] = true;
        dfs(node, dist + d);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    is_visited[1] = true;
    dfs(1, 0);
    
    answer = 0;
    fill_n(is_visited, 10001, false);
    is_visited[far_node] = true;
    dfs(far_node, 0);
    cout << answer;
    return 0;
}