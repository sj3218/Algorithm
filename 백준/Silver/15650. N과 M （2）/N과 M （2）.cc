#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;

int is_visited[10];
int answer[10];

void recursive(int idx, int start)
{
    if (idx == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; ++i)
    {
        if (is_visited[i])
            continue;

        is_visited[i] = true;
        answer[idx] = i;
        recursive(idx + 1, i+1);
        is_visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    recursive(0,1);

    return 0;
}