
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int node_cnt;
int K;
int K_idx;

int nodes[1001];
int parent[1001];
int child_cnt[1001];

void Input()
{
    fill_n(parent, 1001, -1);
    fill_n(child_cnt, 1001, 0);

    for (int i = 0; i < node_cnt; ++i)
    {
        cin >> nodes[i];
        if (nodes[i] == K)
            K_idx = i;
    }
}

void CalculateChildNodeCnt()
{
    int parent_idx = -1;

    for (int i = 1; i < node_cnt; ++i)
    {
        if (nodes[i] - nodes[i - 1] != 1)
        {
            ++parent_idx;
        }
        parent[i] = parent_idx;
        child_cnt[parent_idx]++;
    }
}

int Solution()
{
    int p = parent[K_idx];
    int pp = parent[p];

    int cnt = 0;
    for (int i = 0; i < node_cnt; ++i)
    {
        if (parent[i] == pp && i != p)
            cnt += child_cnt[i];
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true)
    {
        cin >> node_cnt >> K;
        if (node_cnt == 0 && K == 0)
        {
            break;
        }

        Input();
        CalculateChildNodeCnt();
        cout << Solution() << "\n";
    }

    return 0;
}