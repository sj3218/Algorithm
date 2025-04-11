#include <iostream>
#include <algorithm>
#define INF 1000000000
using namespace std;

int N, C;
int arr[200001];

int Count(int length)
{
    int idx = 0;
    int cnt = 0;

    while (idx != N)
    {
        ++cnt;
        idx = lower_bound(arr + idx, arr + N, arr[idx] + length) - arr;
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> C;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    int start = 1;
    int end = INF;
    int mid;
    int answer = 0;
    int cnt;

    while (start <= end)
    {
        mid = (start + end ) / 2;
        cnt = Count(mid);

        if (cnt < C)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            answer = max(answer, mid);
        }
    }

    cout << answer;
    return 0;
}
