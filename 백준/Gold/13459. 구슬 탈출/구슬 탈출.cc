#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

#define BOARD_SIZE  11
#define SUCCESS     1
#define FAIL        0
#define EMPTY       '.'
#define WALL        '#'
#define HOLE        'O'
#define RED         'R'
#define BLUE        'B'
#define TIME_END    10

using namespace std;

int height, width;
char board[BOARD_SIZE][BOARD_SIZE];
pair<int, int> red_pos;
pair<int, int> blue_pos;
bool is_visited[BOARD_SIZE][BOARD_SIZE][BOARD_SIZE][BOARD_SIZE];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

//dist, x, y
tuple<int, int, int> Move(int x, int y, int dir)
{
    int dist = 0;
    int nx = x;
    int ny = y;

    while (true)
    {
        nx = x + dx[dir];
        ny = y + dy[dir];
        
        if (board[nx][ny] == WALL)
        {
            break;
        }

        x = nx;
        y = ny;
        ++dist;

        if (board[nx][ny] == HOLE)
        {
            break;
        }
    }

    return { dist, x,y };
}

bool Solution()
{
    bool answer = false;

    queue<tuple<int, pair<int, int>, pair<int, int>>> q;
    q.push({ 0, red_pos, blue_pos });
    is_visited[red_pos.first][red_pos.second][blue_pos.first][blue_pos.second] = true;

    int cur_time;
    int rx, ry;
    int bx, by;
    tuple<int, int, int> next_red; //distance, x, y
    tuple<int, int, int> next_blue;
    int red_dist, next_rx, next_ry, blue_dist, next_bx, next_by;

    while (!q.empty())
    {
        cur_time = get<0>(q.front());
        rx = get<1>(q.front()).first;
        ry = get<1>(q.front()).second;
        bx = get<2>(q.front()).first;
        by = get<2>(q.front()).second;

        q.pop();

        if (cur_time >= TIME_END)
            continue;

        for (int i = 0; i < 4; ++i)
        {
            tie(red_dist, next_rx, next_ry) = Move(rx, ry, i);
            tie(blue_dist, next_bx, next_by) = Move(bx, by, i);

            if (board[next_bx][next_by] == HOLE)
                continue;

            if (board[next_rx][next_ry] == HOLE)
            {
                answer = true;
                break;
            }

            if (next_rx == next_bx && next_ry == next_by)
            {
                if (red_dist < blue_dist)
                {
                    next_bx -= dx[i];
                    next_by -= dy[i];
                }
                else
                {
                    next_rx -= dx[i];
                    next_ry -= dy[i];
                }
            }

            if (is_visited[next_rx][next_ry][next_bx][next_by])
                continue;

            is_visited[next_rx][next_ry][next_bx][next_by] = true;
            q.push({ cur_time + 1, {next_rx, next_ry}, {next_bx, next_by} });
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    fill_n(&is_visited[0][0][0][0], BOARD_SIZE * BOARD_SIZE * BOARD_SIZE * BOARD_SIZE, false);

    cin >> height >> width;
    string s;
    for (int i = 1; i <= height; ++i)
    {
        cin >> s;
        for (int j = 1; j <= width; ++j)
        {
            board[i][j] = s[j - 1];
            if (board[i][j] == BLUE)
            {
                board[i][j] = EMPTY;
                blue_pos = { i,j };
            }
            else if (board[i][j] == RED)
            {
                board[i][j] = EMPTY;
                red_pos = { i,j };
            }
        }
    }

    if (Solution())
        cout << SUCCESS;
    else
        cout << FAIL;

    return 0;
}