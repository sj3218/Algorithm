#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N, M;
int arr[10];

int is_visited[10];
int answer[10];

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

    int tmp = 0;
    for (int i = 0; i < N; ++i)
    {
        if (is_visited[i] || tmp == arr[i])
            continue;

        tmp = arr[i];
        is_visited[i] = true;
        answer[idx] = arr[i];
        recursive(idx + 1);
        is_visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    recursive(0);

    return 0;
}