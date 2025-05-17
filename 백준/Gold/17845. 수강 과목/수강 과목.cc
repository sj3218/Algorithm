#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int l, s;
vector<pair<int, int>> studies;
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < K; ++i)
    {
        cin >> l >> s;
        studies.push_back({ l,s });
    }

    for (pair<int, int> study : studies)
    {
        for (int i = N; i >= study.second; --i)
        {
            dp[i] = max(dp[i], dp[i - study.second] + study.first);
        }
    }

    cout << dp[N];
    return 0;
}