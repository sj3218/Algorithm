#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
bool is_visited[9];
int answer[9];

void recursive(int idx)
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


    for (int i = 1; i <= N; ++i)
    {
        if (is_visited[i])
            continue;

        answer[idx] = i;
        is_visited[i] = true;
        recursive(idx + 1);
        is_visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    recursive(0);

    return 0;
}