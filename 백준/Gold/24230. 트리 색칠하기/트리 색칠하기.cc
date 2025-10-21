
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int N;
int color[200001];
vector<int> trees[200001];
bool is_visited[200001];

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> color[i];
    }

    int a, b;
    vector<vector<int>> relations(200001);
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> a >> b;
        relations[a].push_back(b);
        relations[b].push_back(a);
    }

    //make tree;
    queue<int> q;
    q.push(1);
    is_visited[1] = true;

    while (!q.empty())
    {
        int curr = q.front(); q.pop();

        for (int i : relations[curr])
        {
            if (is_visited[i])
                continue;
            q.push(i);
            trees[curr].push_back(i);
            is_visited[i] = true;
        }
    }
}

int Solution()
{
    int cnt = 0;

    if (color[1] != 0)
        ++cnt;

    queue<int> q;
    q.push(1);
    int curr;
    int c;
    while (!q.empty())
    {
        curr = q.front(); q.pop();
        c = color[curr];
        for (int i : trees[curr])
        {
            if (c != color[i])
                ++cnt;
            q.push(i);
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    cout << Solution();

    return 0;
}