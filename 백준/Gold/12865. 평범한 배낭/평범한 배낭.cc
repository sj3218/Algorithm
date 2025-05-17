#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0X7FFFFFFF

using namespace std;

int N, K;
int w, v;
vector<pair<int, int>> items;
int dp[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> w >> v;
        items.push_back({ w,v });
    }

    for (pair<int, int> item : items)
    {
        for (int i = K; i >= item.first; --i)
        {
            dp[i] = max(dp[i], dp[i - item.first] + item.second);
        }
    }

    cout << dp[K];
    return 0;
}