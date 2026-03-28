#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <stack>

using namespace std;
int building_cnt;
int building_height[100001];
int cnt[100001];
int idx[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> building_cnt;
    for (int i = 1; i <= building_cnt; ++i)
    {
        cin >> building_height[i];
    }

    stack<pair<int, int>> right_s, left_s;//height, idx
    int height = 0;
    
    for (int i = 1; i <= building_cnt; ++i)
    {
        height = building_height[i];
        while (!left_s.empty() && left_s.top().first <= height)
            left_s.pop();
        cnt[i] = left_s.size();
        if (!left_s.empty())
            idx[i] = left_s.top().second;
        left_s.push({ height, i });
    }

    for (int i = building_cnt; i > 0; --i)
    {
        height = building_height[i];
        while (!right_s.empty() && right_s.top().first <= height)
            right_s.pop();
        cnt[i] += right_s.size();
        if (!right_s.empty())
        {
            if (idx[i] == 0 || i - idx[i] > right_s.top().second - i)
            {
                idx[i] = right_s.top().second;
            }
        }
        right_s.push({ height, i });
    }

    for (int i = 1; i <= building_cnt; ++i)
    {
        cout << cnt[i] << " ";
        if (idx[i] != 0)
            cout << idx[i];

        cout << "\n";
    }
    return 0;
}