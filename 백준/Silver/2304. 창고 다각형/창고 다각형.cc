#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int N;
int height[1001];
int total_sum = 0;
const int INF = 0X7FFFFFFF;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int l, h;
    int left_max = 0, right_max = 0;
    int l_idx = INF;
    int r_idx = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> l >> h;
        height[l] = h;
        l_idx = min(l, l_idx);
        r_idx = max(l, r_idx);
    }
    
    while (l_idx <= r_idx)
    {
        if (height[l_idx] <= height[r_idx])
        {
            if (height[l_idx] >= left_max)
            {
                total_sum += height[l_idx];
                left_max = height[l_idx];
            }
            else
            {
                total_sum += left_max;
            }
            ++l_idx;
        }
        else
        {
            if (height[r_idx] >= right_max)
            {
                total_sum += height[r_idx];
                right_max = height[r_idx];
            }
            else
            {
                total_sum += right_max;
            }
            --r_idx;
        }
    }

    cout << total_sum;
    return 0;
}