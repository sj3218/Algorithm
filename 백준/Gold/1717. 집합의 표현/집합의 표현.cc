#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int parent[1000001];
int n, m;

int Find(int x)
{
    int root = x;
    while (parent[root] >= 0)
        root = parent[root];

    while (x != root) {
        int next = parent[x];
        parent[x] = root;
        x = next;
    }
    return root;
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;

    if (parent[x] == parent[y])
        parent[x]--;

    if (parent[x] < parent[y])
        parent[y] = x;
    else
        parent[x] = y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(parent, 1000001, -1);
    cin >> n >> m;

    int oper, a, b;
    for (int i = 0; i < m; ++i)
    {
        cin >> oper >> a >> b;

        //union
        if (oper == 0)
        {
            if (a == b)
                continue;
            Union(a, b);
        }
        else
        {
            a = Find(a);
            b = Find(b);
            if (a == b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}