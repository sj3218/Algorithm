#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <map>
#include <set>

using namespace std;

map<string, int> friends;//friend_name, idx
int friend_cnt;
int test_case;
int parent[200005];
int size_[200005];

int Find(int u)
{
    while (parent[u] >= 0)
    {
        u = parent[u];
    }
    return u;
}

int Union(int u, int v)
{
    u = Find(u);
    v = Find(v);

    if (u == v)
        return size_[u];

    if (parent[u] == parent[v])
        parent[u]--;

    if (parent[u] < parent[v])
    {
        parent[v] = u;
        size_[u] += size_[v];
        return size_[u];
    }
    
    parent[u] = v;
    size_[v] += size_[u];
    return size_[v];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> test_case;
    string f1, f2;
    int idx = 0;
    while (test_case--)
    {
        cin >> friend_cnt;
        friends.clear();
        fill_n(parent, 200005, -1);
        fill_n(size_, 200005, 1);

        for (int i = 0; i < friend_cnt; ++i)
        {
            cin >> f1 >> f2;
            if (friends.find(f1) == friends.end())
            {
                friends[f1] = idx++;
            }
            if (friends.find(f2) == friends.end())
            {
                friends[f2] = idx++;
            }

            cout << Union(friends[f1], friends[f2])<<"\n";
        }
    }

    return 0;
}