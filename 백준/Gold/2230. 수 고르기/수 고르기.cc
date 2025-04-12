#include <iostream>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

int N, M;
int arr[100001];

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
    int answer = INF;
    int idx;

    for (int i = 0; i < N; ++i)
    {
        idx = lower_bound(arr + i, arr + N, arr[i] + M) - arr;
        if (idx < N)
        {
            answer = min(answer, arr[idx] - arr[i]);
        }
    }

    cout << answer;
    return 0;
}
