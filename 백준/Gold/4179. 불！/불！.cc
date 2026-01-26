#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;

const char WALL = '#';
const char EMPTY = '.';
const char FIRE = 'F';

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

int R, C;
char board[1001][1001];

queue<pair<int, int>> q_fire_pos;
queue<pair<int, int>> q_jihoon_pos;
int fire_time[1001][1001];
int is_visited[1001][1001];

bool OutofBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > R || c > C)
    {
        return true;
    }
    return false;
}

void Input()
{
    cin >> R >> C;

    for (int r = 1; r <= R; ++r)
    {
        for (int c = 1; c <= C; ++c)
        {
            cin >> board[r][c];
            if (board[r][c] == 'J')
            {
                q_jihoon_pos.push({ r,c });
                is_visited[r][c] = 1;
            }
            else if (board[r][c] == FIRE)
            {
                q_fire_pos.push({ r,c });
                fire_time[r][c] = 1;
            }
        }
    }
}

void ProcessFire()
{
    int r, c;
    int nr, nc;
    int cnt;

    while (!q_fire_pos.empty())
    {
        tie(r, c) = q_fire_pos.front();
        q_fire_pos.pop();
        cnt = fire_time[r][c];

        for (int i = 0; i < 4; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];

            if (OutofBound(nr, nc)) continue;
            if (board[nr][nc] == WALL) continue;
            if (fire_time[nr][nc] != 0) continue;

            fire_time[nr][nc] = cnt + 1;
            q_fire_pos.push({ nr,nc });
        }
    }
}

bool CanEscape(int& distance)
{
    int r, c;
    int nr, nc;
    int cnt;

    while (!q_jihoon_pos.empty())
    {
        tie(r, c) = q_jihoon_pos.front();
        q_jihoon_pos.pop();
        cnt = is_visited[r][c];

        for (int i = 0; i < 4; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];

            if (OutofBound(nr, nc))
            {
                distance = cnt;
                return true;
            }

            if (board[nr][nc] == WALL) continue;
            if (is_visited[nr][nc] != 0) continue;
            if (fire_time[nr][nc] != 0 && fire_time[nr][nc] <= cnt + 1) continue;


            is_visited[nr][nc] = cnt + 1;
            q_jihoon_pos.push({ nr,nc });
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int distance = 0;

    Input();
    ProcessFire();

    if (CanEscape(distance))
        cout << distance;
    else
        cout << "IMPOSSIBLE";

    return 0;
}