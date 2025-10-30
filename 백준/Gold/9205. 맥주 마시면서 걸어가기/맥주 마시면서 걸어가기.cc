#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int T;
int store_cnt;
vector<pair<int, int>> pos;
const int CAN_WALK_ = 1000;

void Input()
{
    pos = vector<pair<int, int>>();
    cin >> store_cnt;
    
    int x, y;
    for (int i = 0; i < store_cnt + 2; ++i)
    {
        cin >> x >> y;
        pos.push_back({ x,y });
    }
}

int Dist(pair<int, int> a, pair<int, int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void bfs()
{
    queue<int> q;
    vector<bool> is_visited(store_cnt + 2, false);

    q.push(0);
    is_visited[0] = true;
    int cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        if (Dist(pos[cur], pos[store_cnt + 1]) <= CAN_WALK_)
        {
            cout << "happy\n";
            return;
        }

        for (int i = 1; i <= store_cnt; ++i)
        {
            if (is_visited[i])
                continue;
            if (Dist(pos[cur], pos[i]) <= CAN_WALK_)
            {
                is_visited[i] = true;
                q.push(i);
            }
        }
    }

    cout << "sad\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        Input();
        bfs();
    }

    return 0;
}