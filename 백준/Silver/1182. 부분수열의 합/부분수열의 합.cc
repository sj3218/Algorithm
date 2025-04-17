#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, S;
int arr[21];
int answer = 0;

void recursive(int cur, int total)
{
    if (cur == N)
    {
        if (total == S)
            ++answer;
        return;
    }

    recursive(cur + 1, total);
    recursive(cur + 1, total + arr[cur]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> S;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    recursive(0, 0);
    if (S == 0)
        --answer;

    cout << answer;

    return 0;
}