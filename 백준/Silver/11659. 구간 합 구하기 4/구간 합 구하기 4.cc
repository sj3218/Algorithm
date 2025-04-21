#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arr[100001];
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        dp[i] = arr[i] + dp[i-1];
    }

    int x, y;

    for (int i = 0; i < M; ++i)
    {
        cin >> x >> y;
        cout << dp[y] - dp[x-1] << "\n";
    }
    return 0;
}