#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int H, W;
int height[501];
int total_water = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> H >> W;

    for (int i = 0; i < W; ++i)
    {
        cin >> height[i];
    }

    int l = 0, r = W-1;
    int left_max = 0;
    int right_max = 0;

    while (l < r)
    {
        if (height[l] <= height[r])
        {
            if (height[l] >= left_max)
                left_max = height[l];
            else
                total_water += left_max - height[l];
            ++l;
        }
        else
        {
            if (height[r] >= right_max)
                right_max = height[r];
            else
                total_water += right_max - height[r];
            --r;
        }
    }

    cout << total_water;
    return 0;
}