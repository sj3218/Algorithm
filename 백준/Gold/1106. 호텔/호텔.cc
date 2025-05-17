#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0X7FFFFFFF
#define MAX_CUSTOMER 11001

using namespace std;

int C, N;
vector<pair<int, int>> information;
int dp[MAX_CUSTOMER];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> C >> N;
    int cost, customer;
    for (int i = 0; i < N; ++i)
    {
        cin >> cost >> customer;
        information.push_back({ cost, customer });
    }

    fill_n(dp, MAX_CUSTOMER, INF);
    dp[0] = 0;

    for (pair<int, int> info : information)
    {
        for (int i = info.second; i < MAX_CUSTOMER; ++i)
        {
            if (dp[i - info.second] == INF)
                continue;
            dp[i] = min(dp[i], dp[i - info.second] + info.first);
        }
    }

    cout << *min_element(dp + C, dp + MAX_CUSTOMER);
    return 0;
}