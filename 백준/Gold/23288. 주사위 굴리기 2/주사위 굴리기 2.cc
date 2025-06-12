#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

#define MAX_BOARD_SIZE      21
#define EAST                0
#define WEST                1
#define SOUTH               2
#define NORTH               3

int height, width, move_count;
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int dice[4][4];
tuple<int,int,int> dice_info;//r,c,dir
bool is_visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

int score = 0;

int dx[4] = { 0,0,1,-1 }; //E, W, S, N
int dy[4] = { 1,-1,0,0 };

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > height || c > width)
        return true;
    return false;
}

int bfs(int r, int c, int num)
{
    fill_n(&is_visited[0][0], MAX_BOARD_SIZE * MAX_BOARD_SIZE, false);

    queue<pair<int, int>> q;
    q.push({ r,c });
    is_visited[r][c] = true;
    int cnt = 1;
    int cx, cy;
    int nx, ny;

    while (!q.empty())
    {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (OutOfBound(nx, ny))
                continue;
            if (is_visited[nx][ny])
                continue;
            if (board[nx][ny] != num)
                continue;

            is_visited[nx][ny] = true;
            q.push({ nx,ny });
            ++cnt;
        }
    }
    return cnt;
}

void Input()
{
    cin >> height >> width >> move_count;

    for (int i = 1; i <= height; ++i)
    {
        for (int j = 1; j <= width; ++j)
        {
            cin >> board[i][j];
        }
    }

    //set dice information
    dice_info = { 1,1,0 };//r,c,d

    dice[1][0] = 4;
    dice[1][1] = 1;
    dice[1][2] = 3;
    dice[1][3] = 6;
    dice[0][1] = 2;
    dice[2][1] = 5;
    dice[3][1] = 6;
}

int ChangeDirection(int dir)
{
    if (dir == EAST)
        dir = WEST;
    else if (dir == WEST)
        dir = EAST;
    else if (dir == SOUTH)
        dir = NORTH;
    else
        dir = SOUTH;

    get<2>(dice_info) = dir;
    return dir;
}

void MoveDice()
{
    int r, c, d;
    tie(r, c, d) = dice_info;
    int nr, nc;
    nr = r + dx[d];
    nc = c + dy[d];

    if (OutOfBound(nr, nc))
    {
        d = ChangeDirection(d);
        nr = r + dx[d];
        nc = c + dy[d];
    }

    int last;
    if (d == EAST)
    {
        last = dice[1][3];
        for (int i = 3; i > 0; --i)
        {
            dice[1][i] = dice[1][i - 1];
        }
        dice[1][0] = last;
        dice[3][1] = dice[1][3];
    }
    else if (d == WEST)
    {
        last = dice[1][0];
        for (int i = 0; i < 3; ++i)
        {
            dice[1][i] = dice[1][i + 1];
        }
        dice[1][3] = last;
        dice[3][1] = dice[1][3];
    }
    else if (d == SOUTH)
    {
        last = dice[3][1];
        for (int i = 3; i > 0; --i)
        {
            dice[i][1] = dice[i - 1][1];
        }
        dice[0][1] = last;
        dice[1][3] = dice[3][1];
    }
    else
    {
        last = dice[0][1];
        for (int i = 0; i < 3; ++i)
        {
            dice[i][1] = dice[i + 1][1];
        }
        dice[3][1] = last;
        dice[1][3] = dice[3][1];
    }
    
    dice_info = { nr,nc,d };
}

void RotateDirection(bool is_clockwise)
{
    int dir = get<2>(dice_info);

    if (is_clockwise)
    {
        if (dir == EAST)
            dir = SOUTH;
        else if (dir == SOUTH)
            dir = WEST;
        else if (dir == WEST)
            dir = NORTH;
        else
            dir = EAST;
    }
    else
    {
        if (dir == EAST)
            dir = NORTH;
        else if (dir == NORTH)
            dir = WEST;
        else if (dir == WEST)
            dir = SOUTH;
        else
            dir = EAST;
    }
    get<2>(dice_info) = dir;
}

void RotateDice(int a, int b)
{
    if (a == b)
        return;
    else if (a < b)
    {
        //rotate counter-clockwise
        RotateDirection(false);
    }
    else
    {
        //rotate clockwise
        RotateDirection(true);
    }
}

void Solution()
{
    int r, c, d;

    for (int i = 0; i < move_count; ++i)
    {
        MoveDice();
        
        tie(r, c, d) = dice_info;
        score += board[r][c] * bfs(r, c, board[r][c]);

        RotateDice(dice[1][3], board[r][c]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();
    cout << score;

    return 0;
}