#include <iostream>
#include <algorithm>
#include <tuple>
#include <stack>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int curr_tower_height, pre_tower_height = 0;
    int idx;
    stack<pair<int, int>> highest_tower;
    
    for (int i = 1; i <= N; ++i)
    {
        cin >> curr_tower_height;

        while (!highest_tower.empty())
        {
            tie(idx, pre_tower_height) = highest_tower.top();
            if (pre_tower_height < curr_tower_height)
            {
                highest_tower.pop();
            }
            else
            {
                highest_tower.push({ i, curr_tower_height });
                cout << idx << " ";
                break;
            }
        }

        if (highest_tower.empty())
        {
            cout << "0 ";
            highest_tower.push({ i, curr_tower_height });
        }
    }

    
    return 0;
}