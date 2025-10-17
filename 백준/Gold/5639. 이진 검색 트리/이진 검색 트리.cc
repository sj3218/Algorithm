
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int head;
int preorder[10001];

int Input()
{
    int x;
    int idx = 0;
    while (cin >> x)
    {
        preorder[idx++] = x;
    }

    return idx;
}

void dfs(int start, int end)
{
    if (start >= end)
        return;

    int root = preorder[start];
    int mid = start + 1;
    while (mid < end && preorder[mid] < root)
    {
        mid++;
    }

    dfs(start + 1, mid);
    dfs(mid, end);

    cout << root<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int size = 0;
    size = Input();

    dfs(0, size);

    return 0;
}