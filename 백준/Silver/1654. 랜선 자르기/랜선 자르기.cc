#include <iostream>
#include <algorithm>

using namespace std;

int K, N;
int arr[10001];

long binarysearch(int e)
{
    long start = 1;
    long end = e;

    long mid=0;
    long answer = 0;
    
    while (start <= end)
    {
        mid = (start + end) / 2;
        int cnt = 0;

        for (int i = 0; i < K; ++i)
        {
            cnt += arr[i] / mid;
        }

        if (cnt < N)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            answer = max(answer, mid);
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> K >> N;
    int max_length = 0;

    for (int i = 0; i < K; ++i)
    {
        cin >> arr[i];
        max_length = max(max_length, arr[i]);
    }

    cout << binarysearch(max_length);

    return 0;
}