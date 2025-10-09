
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int gate_cnt;
int flight_cnt;
int parent[100001];

int Find(int i)
{
    if (parent[i] == i)
        return i;
    return parent[i] = Find(parent[i]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    parent[a] = b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 1; i <= 100000; ++i)
    {
        parent[i] = i;
    }

    cin >> gate_cnt >> flight_cnt;

    int g;
    int gate;
    int cnt = 0;
    for (int i = 0; i < flight_cnt; ++i) 
    {
        cin >> g;
        gate = Find(g);

        if (gate == 0)
            break;

        Union(gate, gate - 1);
        ++cnt;
    }

    cout << cnt;
    return 0;
}