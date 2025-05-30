#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int total_floor;
int goal_pos;
int start_pos;
int button[2];

int is_visited[1000001];

bool bfs()
{
    queue<int> q;
    q.push(start_pos);
    is_visited[start_pos] = 0;

    int curr, next;
    int cnt;
    while (!q.empty())
    {
        curr = q.front();
        cnt = is_visited[curr];
        q.pop();
        if (curr == goal_pos)
            return true;

        for (int i = 0; i < 2; ++i)
        {
            next = curr + button[i];
            if (next <= 0 || next > total_floor)
                continue;
            if (is_visited[next] != -1)
                continue;

            is_visited[next] = cnt + 1;
            q.push(next);
        }
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(is_visited, 1000001, -1);
    cin >> total_floor >> start_pos >> goal_pos >> button[0] >> button[1];
    button[1] = -button[1];
    if (bfs())
        cout << is_visited[goal_pos];
    else
        cout << "use the stairs";
    

    return 0;
}
