#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int test_case;
int W, H;
char map[1001][1001];
int pos_J_r, pos_J_c;
int is_visited[1001][1001];
int fire_visited[1001][1001];
queue<pair<int, int>> q_fire;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0, 0 };

void Input()
{
    fill_n(is_visited[0], 1001 * 1001, -1);
    fill_n(fire_visited[0], 1001 * 1001, -1);

    cin >> W >> H;
    string ss;
    for (int i = 0; i < H; ++i)
    {
        cin >> ss;

        for (int j = 0; j < W; ++j)
        {
            if (ss[j] == '@')
            {
                pos_J_r = i;
                pos_J_c = j;
            }
            else if (ss[j] == '*')
            {
                q_fire.push({ i, j });
                fire_visited[i][j] = 0;
            }

            map[i][j] = ss[j];
        }
    }
}

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= H || y >= W)
        return false;
    return true;
}

void FireBFS()
{
    while (!q_fire.empty())
    {
        int x = q_fire.front().first;
        int y = q_fire.front().second;
        q_fire.pop();

        int curr_fire = fire_visited[x][y];

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!IsValid(nx, ny) || fire_visited[nx][ny] != -1)
                continue;

            if (map[nx][ny] == '#')
                continue;

            q_fire.push({ nx, ny });
            fire_visited[nx][ny] = curr_fire + 1;
        }
    }
}

int bfs()
{
    queue<pair<int, int>> q;
    q.push({ pos_J_r, pos_J_c });
    is_visited[pos_J_r][pos_J_c] = 0;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int curr_time = is_visited[x][y];
        q.pop();

        if (x == 0 || x == H - 1 || y == 0 || y == W - 1)
        {
            return is_visited[x][y] + 1;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny] != -1)
            {
                continue;
            }

            if (fire_visited[nx][ny] > curr_time + 1 || fire_visited[nx][ny] == -1)
            {
                if (map[nx][ny] == '.')
                {
                    q.push({ nx, ny });
                    is_visited[nx][ny] = curr_time + 1;
                }
            }

        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    cin >> test_case;
    for (int i = 0; i < test_case; ++i)
    {
        Input();
        FireBFS();
        int answer = bfs();

        if (answer == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << answer << "\n";
    }
    
    return 0;
}