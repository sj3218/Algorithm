#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
#define INF 0X7FFFFFFF

int city_cnt, plan_city_cnt;
int plan_city[1001];
vector<int> cities[201];
bool is_visited[201][201];

void Input()
{
    cin >> city_cnt >> plan_city_cnt;
    int connected;
    for (int i = 1; i <= city_cnt; ++i)
    {
        for (int j = 1; j <= city_cnt; ++j)
        {
            cin >> connected;
            if (connected == 1)
            {
                cities[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < plan_city_cnt; ++i)
    {
        cin >> plan_city[i];
    }
}

void ConnectCity(int start)
{
    queue<int> q;
    q.push(start);
    is_visited[start][start] = true;

    int x;
    while (!q.empty())
    {
        x = q.front(); q.pop();
        
        for (int nx : cities[x])
        {
            if (is_visited[start][nx])
                continue;

            is_visited[start][nx] = true;
            q.push(nx);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    for (int i = 1; i <= city_cnt; ++i)
    {
        ConnectCity(i);
    }

    int x, y;
    bool can_go = true;
    for (int i = 1; i < plan_city_cnt; ++i)
    {
        x = plan_city[i - 1];
        y = plan_city[i];

        if (!is_visited[x][y])
        {
            can_go = false;
            break;
        }
    }

    if (can_go)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}