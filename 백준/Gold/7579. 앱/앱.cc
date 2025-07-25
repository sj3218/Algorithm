#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int app_cnt;
int need_memory_size;
int using_memory[101];
int unactivate_cost[101];
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> app_cnt >> need_memory_size;
    int total_cost = 0;

    for (int i = 1; i <= app_cnt; ++i)
    {
        cin >> using_memory[i];
    }

    for (int i = 1; i <= app_cnt; ++i)
    {
        cin >> unactivate_cost[i];
        total_cost += unactivate_cost[i];
    }

    for (int i = 1; i <= app_cnt; ++i)
    {
        for (int c = total_cost; c >= unactivate_cost[i]; --c)
        {
            dp[c] = max(dp[c], dp[c - unactivate_cost[i]] + using_memory[i]);
        }
    }

    for (int c = 0; c <= total_cost; ++c)
    {
        if (dp[c] >= need_memory_size)
        {
            cout << c;
            break;
        }
    }
    return 0;
}