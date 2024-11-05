#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(dp, 1001, 0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    int val;
    for (int i = 1; i <= N; ++i)
    {
        val = arr[i];

        for (int j = 1; j < i; ++j)
        {
            if (val > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    cout << *max_element(dp, dp + N + 1);

    return 0;
}