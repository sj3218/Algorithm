#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int N;
vector<int> tree[51];

void Input()
{
    cin >> N;

    int parent;
    cin >> parent; //minsik,,
    for (int i = 1; i < N; ++i)
    {
        cin >> parent;
        tree[parent].push_back(i);
    }
}

int dfs(int curr)
{
    int max_value = 0;
    int value;
    int size = tree[curr].size();
    if (size == 0)
        return 0;

    vector<int> values;

    for (int i : tree[curr])
    {
        value = dfs(i) + 1;
        values.push_back(value);
    }

    sort(values.begin(), values.end(), greater<int>());
    for (int i = 0; i < size; ++i)
    {
        value = values[i] + i;

        max_value = max(max_value, value);
    }

    if (max_value < size)
        return size;
    return max_value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    cout << dfs(0);

    return 0;
}