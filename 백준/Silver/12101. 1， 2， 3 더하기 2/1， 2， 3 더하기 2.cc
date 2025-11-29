#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int dp[12];
int num;
int order;
int stores[12];

bool solution(int& curr_order, int& curr_idx, int total_sum)
{
    if (total_sum == num)
    {
        curr_order++;
        if (curr_order == order)
            return true;
        return false;
    }
    else if (total_sum > num)
        return false;

    for (int i = 1; i <= 3; ++i)
    {
        stores[curr_idx] = i;
        curr_idx += 1;
        if (solution(curr_order, curr_idx, total_sum + i))
        {
            return true;
        }
        curr_idx -= 1;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    fill_n(dp, 12, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 11; ++i)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    cin >> num >> order;
    int curr_order = 0;
    int curr_idx = 0;
    if (solution(curr_order, curr_idx, 0))
    {
        for (int i = 0; i < curr_idx-1; ++i)
        {
            cout << stores[i] << "+";
        }
        cout << stores[curr_idx-1];
    }
    else
        cout << -1;

    return 0;
}