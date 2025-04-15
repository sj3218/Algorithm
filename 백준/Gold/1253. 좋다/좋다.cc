#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[2001];
int answer = 0;

void solution(int i)
{
    int sum;
    int idx;
    for (int j = 0; j < N; ++j)
    {
        if (i == j)
            continue;
        sum = arr[i] - arr[j];

        idx = lower_bound(arr, arr + N, sum) - arr;
        
        while (idx < N && arr[idx] == sum)
        {
            if (idx != i && idx != j)
            {
                ++answer;
                return;
            }
            ++idx;
        }
    }
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

    for (int i = 0; i < N; ++i)
    {
        solution(i);
    }
    cout << answer;
    return 0;
}