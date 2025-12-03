#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int GOAL = 100;
const int DICE_FACE_CNT = 6;

int ladder_cnt;
int snake_cnt;
int has_event[101];
int is_visited[101];

void bfs()
{
    fill_n(is_visited, 101, -1);
    queue<int> q;
    q.push(1);
    is_visited[1] = 0;

    int curr_x;
    int nx;
    while (!q.empty())
    {
        curr_x = q.front(); q.pop();

        if (curr_x == GOAL)
        {
            cout << is_visited[GOAL];
            return;
        }

        for (int i = 1; i <= DICE_FACE_CNT; ++i)
        {
            nx = curr_x + i;
            if(nx > GOAL)
                break;
            
            if (has_event[nx] != 0)
                nx = has_event[nx];

            if (is_visited[nx] != -1 && is_visited[nx] <= is_visited[curr_x] + 1)
                continue;

            is_visited[nx] = is_visited[curr_x] + 1;
            q.push(nx);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    cin >> ladder_cnt >> snake_cnt;
    int size = ladder_cnt + snake_cnt;
    for (int i = 0; i < size; ++i)
    {
        cin >> x >> y;
        has_event[x] = y;
    }

    bfs();

    return 0;
}