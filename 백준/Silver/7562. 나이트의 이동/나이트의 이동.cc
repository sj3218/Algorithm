#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int test_case;
int L;
int curr_x, curr_y;
int goal_x, goal_y;

int is_visited[301][301];

int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= L || y >= L)
        return false;

    return true;
}

void bfs()
{
    queue<pair<int, int>> q;
    q.push({ curr_x, curr_y });
    is_visited[curr_x][curr_y] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == goal_x && y == goal_y)
            return;

        int curr_cnt = is_visited[x][y];

        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny] != -1)
            {
                continue;
            }

            q.push({ nx, ny });
            is_visited[nx][ny] = curr_cnt + 1;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> test_case;

    for (int i = 0; i < test_case; ++i)
    {
        cin >> L;
        cin >> curr_x >> curr_y;
        cin >> goal_x >> goal_y;

        fill_n(is_visited[0], 301 * 301, -1);

        bfs();
        cout << is_visited[goal_x][goal_y] << "\n";
    }
    return 0;
}