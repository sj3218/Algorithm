#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arr[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int start = 0;
    int end = 0;
    int sum = arr[0];
    int answer = 0;

    while (start <= end && start < N && end < N)
    {
        if (sum == M)
        {
            ++answer;
        }

        if (sum <= M)
        {
            ++end;
            sum += arr[end];
        }
        else
        {
            sum -= arr[start];
            
            if (start == end)
            {
                ++end;
                sum += arr[end];
            }
            ++start;
        }
    }

    cout << answer;
    return 0;
}