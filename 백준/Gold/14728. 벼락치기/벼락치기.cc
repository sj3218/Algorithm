#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, T;
int k, s;
vector<pair<int, int>> exam;
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> T;
    for (int i = 0; i < N; ++i)
    {
        cin >> k >> s;
        exam.push_back({ k,s });
    }

    for (pair<int, int> e : exam)
    {
        for (int i = T; i >= e.first; --i)
        {
            dp[i] = max(dp[i], dp[i - e.first] + e.second);
        }
    }

    cout << dp[T];
    return 0;
}