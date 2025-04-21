#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int arr[100001];
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    int answer = dp[1];

    for (int i = 2; i <= N; ++i)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
        answer = max(answer, dp[i]);
    }

    cout << answer;
    return 0;
}