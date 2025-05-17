#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int idx[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
    }

    int val;
    fill_n(dp, 1001, 1);
    fill_n(idx, 1001, -1);

    int max_idx = 1;
    int max_dp = 1;

    for (int i = 2; i <= N; ++i)
    {
        val = arr[i];

        for (int j = 1; j < i; ++j)
        {
            if (val > arr[j])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    idx[i] = j;
                }
            }

            if (max_dp < dp[i])
            {
                max_dp = dp[i];
                max_idx = i;
            }
        }
    }

    cout << dp[max_idx] << "\n";

    vector<int> answer;

    while (max_idx != -1)
    {
        answer.push_back(arr[max_idx]);
        max_idx = idx[max_idx];
    }

    sort(answer.begin(), answer.end(), less<int>());
    for (int next : answer)
    {
        cout << next << " ";
    }
    return 0;
}