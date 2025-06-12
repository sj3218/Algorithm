#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_BOARD_SIZE 500

int board_size;
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

float percentage[10] = { 0.01, 0.01, 0.02,0.02,0.07,0.07,0.1,0.1,0.05,1 };//last one is alpha
//left, down, right, up
int dr[4][10] = { {-1,1,-2,2,-1,1,-1,1,0,0},{-1,-1,0,0,0,0,1,1,2,1},{-1,1,-2,2,-1,1,-1,1,0,0},{1,1,0,0,0,0,-1,-1,-2,-1} };
int dc[4][10] = { {1,1,0,0,0,0,-1,-1,-2,-1},{-1,1,-2,2,-1,1,-1,1,0,0},{-1,-1,0,0,0,0,1,1,2,1},{-1,1,-2,2,-1,1,-1,1,0,0} };
int r, c;
int out_sand = 0;

int dx[4] = { 0,1,0,-1 };//left down right up
int dy[4] = { -1,0,1,0 };

void Input()
{
    cin >> board_size;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cin >> board[i][j];
        }
    }

    r = board_size / 2 + 1;
    c = r;
}

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > board_size || c > board_size)
        return true;
    return false;
}

void SpreadSand(int dir)
{
    if (board[r][c] == 0)
        return;

    int sand = board[r][c];
    if (sand == 0)
        return;

    int nx, ny;
    int spread_sand_amount = 0;
    int curr_sand;
    for (int i = 0; i < 9; ++i)
    {
        nx = r + dr[dir][i];
        ny = c + dc[dir][i];
        curr_sand = percentage[i] * sand;

        if (OutOfBound(nx, ny))
        {
            out_sand += curr_sand;
        }
        else
        {
            board[nx][ny] += curr_sand;
        }

        spread_sand_amount += curr_sand;
    }

    sand -= spread_sand_amount;
    nx = r + dr[dir][9];
    ny = c + dc[dir][9];
    if (OutOfBound(nx, ny))
        out_sand += sand;
    else
        board[nx][ny] += sand;

    board[r][c] = 0;
}

void print_board()
{
    cout << "\n"<< r<<", "<< c<< ", out of sand: "<<out_sand << "\n";
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void Solution()
{
    int move_cnt = 1;
    int dir = 0;
    while (true)
    {
        //dir
        for (int i = 0; i < 2; ++i)
        {
            for (int j = 1; j <= move_cnt; ++j)
            {
                r += dx[dir];
                c += dy[dir];
                SpreadSand(dir);
                //print_board();
            }
            dir++;
            if (dir == 4)
                dir = 0;
        }

        ++move_cnt;
        if (move_cnt == board_size)
        {
            for (int i = 1; i < move_cnt; ++i)
            {
                r += dx[dir];
                c += dy[dir];
                SpreadSand(dir);
            }
            break;
        }
    }

    //print_board();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();
    cout << out_sand;
    return 0;
}