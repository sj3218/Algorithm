#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define BOARD_SIZE 102
#define EMPTY   0
#define APPLE   1
#define SNEAK_BODY    2

using namespace std;

int board_size, apple_cnt;
int r, c;
int dir_cnt;
pair<int, char> dir[BOARD_SIZE];
int board[BOARD_SIZE][BOARD_SIZE];
int dir_idx = 0;

struct Sneak
{
    deque<pair<int, int>> body;
    int dir = 0;
}sneak;

//right, left, down, up
int dx[4] = { 0,0, 1,-1 };
int dy[4] = { 1,-1, 0,0 };

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > board_size || y > board_size)
        return false;
    return true;
}

//update pos of the sneak, return boolean.
//if return true, it can update head pos.
//if return false, it cannot update head pos because of the wall or contact body.
bool UpdateHeadPos()
{
    bool can_update_head = true;

    pair<int, int> cur_pos = sneak.body[0];
    int nx_x = cur_pos.first + dx[sneak.dir];
    int nx_y = cur_pos.second + dy[sneak.dir];

    if (!IsValid(nx_x, nx_y) || board[nx_x][nx_y] == SNEAK_BODY)
    {
        //out of bounds or head pos is in sneak body
        can_update_head = false;
    }
    else if (board[nx_x][nx_y] == EMPTY)
    {
        //there is no apple, remove tail
        int tail_x, tail_y;
        tail_x = sneak.body.back().first;
        tail_y = sneak.body.back().second;
        board[tail_x][tail_y] = EMPTY;
        sneak.body.pop_back();
    }

    //update head pos and board
    sneak.body.push_front({ nx_x, nx_y });
    board[nx_x][nx_y] = SNEAK_BODY;

    return can_update_head;
}

int ChangeDirection(int curr_dir, char c)
{
    if (c == 'L')
    {
        if (curr_dir == 0)
            curr_dir = 3;
        else if (curr_dir == 1)
            curr_dir = 2;
        else if (curr_dir == 2)
            curr_dir = 0;
        else
            curr_dir = 1;
    }
    else
    {
        if (curr_dir == 0)
            curr_dir = 2;
        else if (curr_dir == 1)
            curr_dir = 3;
        else if (curr_dir == 2)
            curr_dir = 1;
        else
            curr_dir = 0;
    }
    return curr_dir;
}

int Solution()
{
    int game_time = 0;
    
    while (true)
    {
        ++game_time;
        
        if (!UpdateHeadPos())
            break;

        //update direction
        if (dir[dir_idx].first == game_time)
        {
            sneak.dir = ChangeDirection(sneak.dir, dir[dir_idx].second);
            ++dir_idx;
        }
    }

    return game_time;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> board_size >> apple_cnt;
    for (int i = 0; i < apple_cnt; ++i)
    {
        cin >> r >> c;
        board[r][c] = APPLE;
    }

    cin >> dir_cnt;
    char c;
    int x;
    for (int i = 0; i < dir_cnt; ++i)
    {
        cin >> x >> c;
        dir[i] = { x,c };
    }

    board[1][1] = SNEAK_BODY;
    sneak.body.push_back({ 1,1 });

    cout << Solution();

    return 0;
}