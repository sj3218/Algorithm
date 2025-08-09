#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N;
int arr[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int val;
    for (int i = 1; i < N; ++i)
    {
        val = arr[i];
        for (int j = 0; j < i; ++j)
        {
            if (arr[j] < val)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    cout << *max_element(dp, dp + N) + 1;
    return 0;
}