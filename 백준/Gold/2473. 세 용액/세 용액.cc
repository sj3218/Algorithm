#include <iostream>
#include <algorithm>
#include <vector>
#define INF 3000000001
using namespace std;

int N;
long long arr[100001];

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

    long long min_sum = INF;
    vector<long long> answer(3);
    long long temp;

    
    for (int i = 0; i < N - 2; ++i)
    {
        int start = i+1;
        int end = N - 1;

        while (start < end)
        {
            temp = arr[i] + arr[start] + arr[end];

            if (abs(temp) < min_sum)
            {
                answer = { arr[i], arr[start],arr[end] };
                min_sum = abs(temp);
            }

            if (temp >= 0)
            {
                --end;
            }
            else
            {
                ++start;
            }
        }
    }

    sort(answer.begin(), answer.end());
    cout << answer[0] << " " << answer[1] << " " << answer[2];
    return 0;
}