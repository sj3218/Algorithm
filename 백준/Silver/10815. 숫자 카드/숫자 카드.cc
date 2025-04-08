#include <iostream>
#include <algorithm>
using namespace std;
int N, M;
int arr[500001];

int binarysearch(int target)
{
    int start = 0;
    int end = N-1;
    int mid;
    
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
            return 1;
    }
    return 0;
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
        cout << binarysearch(num) << " ";
    }
    return 0;
}