#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, X;
vector<vector<int>> arr;
bool is_visited[100001];

int DFS(int idx)
{
    int size = arr[idx].size();

    if (size == 0)
        return 1;

    int ans = 0;
    int n_i = 0;
    for (int i = 0; i < size; ++i)
    {
        n_i = arr[idx][i];

        if (is_visited[n_i] == true)
            continue;

        is_visited[n_i] = true;
        ans += DFS(n_i);
    }

    return ans+1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    arr.assign(N + 1, vector<int>());
    fill_n(is_visited, 100001, false);

    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        arr[b].push_back(a);
    }

    cin >> X;

    is_visited[X] = true;
    cout << DFS(X)-1;
    return 0;
}