#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int TC;
int store_cnt, street_cnt, hole_cnt;
int S, E, T;

vector<tuple<int, int, int>> street_info;
int cost[501];

bool bellman_ford(int start)
{
    fill_n(cost, 501, 0);

    for (int i = 1; i <= start; ++i)
    {
        for (tuple<int, int, int> info : street_info)
        {
            tie(S, E, T) = info;

            if (cost[E] > cost[S] + T)
            {
                cost[E] = cost[S] + T;

                if (i == start)
                    return true;
            }
        }
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> TC;

    while (TC--)
    {
        cin >> store_cnt >> street_cnt >> hole_cnt;

        street_info.clear();
        for (int i = 0; i < street_cnt; ++i)
        {
            cin >> S >> E >> T;
            street_info.push_back({ S,E,T });
            street_info.push_back({ E,S,T });
        }

        for (int i = 0; i < hole_cnt; ++i)
        {
            cin >> S >> E >> T;
            street_info.push_back({ S, E, -T });
        }

        if (bellman_ford(store_cnt))
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;
}