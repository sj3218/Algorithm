#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int build_height[51];
int cnt[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> build_height[i];
    }

    double gradient;
    double diff;
    double value;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (i == j)
                continue;
            bool is_line = false;

            if (build_height[i] == build_height[j])
            {
                gradient = build_height[i];
                is_line = true;
                diff = 0;
            }
            else
            {
                gradient = (double)(build_height[j] - build_height[i]) / (double)(j - i);
                diff = (double)build_height[j] - gradient * (double)j;
            }
            bool can_see = true;
            for (int k = i+1; k < j; ++k)
            {
                if (is_line)
                    value = gradient;
                else
                    value = gradient * k + diff;
                if (value <= build_height[k])
                {
                    can_see = false;
                    break;
                }
            }

            for (int k = j+1; k < i; ++k)
            {
                if (is_line)
                    value = gradient;
                else
                    value = gradient * k + diff;
                if (value <= build_height[k])
                {
                    can_see = false;
                    break;
                }
            }

            if (can_see)
                ++cnt[i];
        }
    }

    int answer = *max_element(cnt, cnt + N+1);
    cout << answer;
    return 0;
}