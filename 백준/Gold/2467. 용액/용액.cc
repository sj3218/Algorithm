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

    int start = 0; 
    int end = N - 1;

    pair<int, int> answer;
    int min_sum = INF;

    while (start < end)
    {
        int sum = arr[start] + arr[end];

        if (abs(sum) < min_sum)
        {
            answer = { arr[start], arr[end] };
            min_sum = abs(sum);
        }
        else if (sum < 0)
        {
            ++start;
        }
        else
        {
            --end;
        }
    }

    cout << answer.first << " " << answer.second;
    return 0;
}