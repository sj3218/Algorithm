#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int col_visited[16];
int right_diagonal_visited[32]; // /방향
int left_diagonal_visited[32]; // \ 방향

int answer = 0;

void recursive(int idx)
{
    if (idx == N)
    {
        ++answer;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (col_visited[i] || right_diagonal_visited[i+idx] || left_diagonal_visited[idx - i + N -1])
            continue;

        col_visited[i] = true;
        right_diagonal_visited[i + idx] = true;
        left_diagonal_visited[idx - i + N - 1] = true;

        recursive(idx + 1);

        col_visited[i] = false;
        right_diagonal_visited[i + idx] = false;
        left_diagonal_visited[idx - i + N - 1] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    recursive(0);
    cout << answer;

    return 0;
}