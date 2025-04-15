#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int requests[10001];
int budget;
int dp[10001];

int solution()
{
    int start = 1;
    int end = budget;
    int mid;
    int answer = 0;

    while (start <= end)
    {
        mid = (start + end) / 2;

        int sum = 0;
        for (int i = 0; i < N; ++i)
        {
            sum += min(mid, requests[i]);
        }

        if (sum <= budget)
        {
            start = mid + 1;
            answer = max(answer, mid);
        }
        else
        {
            end = mid - 1;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> requests[i];
    }
    cin >> budget;
    sort(requests, requests + N);

    for (int i = 0; i < N; ++i)
    {
        if (i == 0)
        {
            dp[i] = requests[i];
            continue;
        }

        dp[i] = dp[i - 1] + requests[i];
    }

    if (dp[N - 1] <= budget)
    {
        cout << requests[N - 1];
    }
    else
    {
        cout << solution();
    }
    return 0;
}