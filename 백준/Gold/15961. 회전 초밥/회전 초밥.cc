#include <iostream>
#include <algorithm>
#include <tuple>
#include <stack>

using namespace std;

int dish_cnt, sushi_cnt;
int successive_dish_cnt, coupon;
int dish[6000002];
int is_visited[3001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> dish_cnt >> sushi_cnt >> successive_dish_cnt >> coupon;

    for (int i = 0; i < dish_cnt; ++i)
    {
        cin >> dish[i];
        dish[i + dish_cnt] = dish[i];
    }

    int sushi;
    int cnt = 0;
    for (int i = 0; i < successive_dish_cnt; ++i)
    {
        sushi = dish[i];
        if (is_visited[sushi] == 0)
            ++cnt;

        is_visited[sushi]++;
    }

    //used coupon
    if (is_visited[coupon] == 0)
        ++cnt;

    int pre_dish;
    int max_cnt = cnt;
    int total_size = dish_cnt + successive_dish_cnt;
    for (int i = successive_dish_cnt; i < total_size; ++i)
    {
        sushi = dish[i];
        pre_dish = dish[i - successive_dish_cnt];

        //add next sushi dish
        if (is_visited[sushi] == 0)
        {
            //if the current sushi of dish is the coupon dish, then already used coupon.
            //so do not ++cnt
            if (sushi != coupon)
            {
                ++cnt;
            }
        }
        is_visited[sushi]++;

        //delete pre sushi dish
        is_visited[pre_dish]--;
        if (is_visited[pre_dish] == 0)
        {
            //if the current dish is the coupon dish, then need to use coupon.
            //so just stay the cnt;
            if(pre_dish != coupon)
                --cnt;
        }

        //update the max cnt;
        max_cnt = max(max_cnt, cnt);
    }
    
    cout << max_cnt;
    return 0;
}