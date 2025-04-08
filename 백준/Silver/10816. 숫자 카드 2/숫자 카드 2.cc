#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[500001];

int lower(int target)
{
    int start = 0;
    int end = N;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
            end = mid;
    }
    return start;
}
int upper(int target)
{
    int start = 0;
    int end = N;
    while (start < end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] <= target)
        {
            start = mid + 1;
        }
        else
            end = mid;
    }
    return start;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    cin >> M;
    int num;
    for (int i = 0; i < M; ++i)
    {
        cin >> num;

        cout << upper(num) - lower(num) << " ";
    }
    return 0;
}