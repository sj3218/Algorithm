#include <iostream>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;

int N;
int arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int min_sum = INF;
    int answer;
    int idx;

    for (int i = 0; i < N - 1; ++i)
    {
        idx = lower_bound(arr + i + 1, arr + N, -arr[i]) - arr;

        if (idx < N && abs(arr[i] + arr[idx]) < min_sum)
        {
            answer = arr[i] + arr[idx];
            min_sum = abs(answer);
        }

        if (idx - 1 > i && abs(arr[i] + arr[idx - 1]) < min_sum)
        {
            answer = arr[i] + arr[idx - 1];
            min_sum = abs(answer);
        }
    }

    cout << answer;

    return 0;
}