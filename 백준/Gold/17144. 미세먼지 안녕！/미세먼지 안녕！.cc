#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;
#define BOARD_SIZE 51
#define DIVIDE      5

int R, C, T;
int board[BOARD_SIZE][BOARD_SIZE];
int top_cleaner_r;
int bottom_cleaner_r;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsValid(int r, int c)
{
    if (r <= 0 || c <= 0 || r > R || c > C)
        return false;
    return true;
}

void Input()
{
    cin >> R >> C >> T;
    vector<pair<int, int>> cleaner_pos;

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == -1)
                cleaner_pos.push_back({ i,j });
        }
    }
    top_cleaner_r = cleaner_pos[0].first;
    bottom_cleaner_r = top_cleaner_r + 1;
}

int CalcTotalDust()
{
    int total = 0;

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (board[i][j] == -1)
                continue;

            total += board[i][j];
        }
    }
    return total;
}

void CopyBoard(int a[][BOARD_SIZE], int b[][BOARD_SIZE])
{
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            a[i][j] = b[i][j];
        }
    }
}

void SpreadDust()
{
    int temp[BOARD_SIZE][BOARD_SIZE];
    fill_n(&temp[0][0], BOARD_SIZE * BOARD_SIZE, 0);
    temp[top_cleaner_r][1] = -1;
    temp[bottom_cleaner_r][1] = -1;

    int dust, spread_amount;
    int nx, ny;
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            dust = board[i][j];
            if (dust == 0 || dust == -1)
                continue;

            int cnt = 0;
            for (int k = 0; k < 4; ++k)
            {
                nx = i + dx[k];
                ny = j + dy[k];
                if (!IsValid(nx, ny) || board[nx][ny] == -1)
                {
                    continue;
                }
                ++cnt;
            }

            spread_amount = dust / DIVIDE;
            dust = dust - spread_amount * cnt;
            temp[i][j] += dust;
            
            for (int k = 0; k < 4; ++k)
            {
                nx = i + dx[k];
                ny = j + dy[k];
                if (!IsValid(nx, ny) || board[nx][ny] == -1)
                {
                    continue;
                }
                temp[nx][ny] += spread_amount;
            }

        }
    }

    CopyBoard(board, temp);
}

void OperateCleaner()
{
    //top counter-clockwise
    //left top corner to left bottom
    for (int i = top_cleaner_r - 1; i > 1; --i)
    {
        board[i][1] = board[i - 1][1];
    }
    //right-top to left-top
    for (int i = 1; i < C; ++i)
    {
        board[1][i] = board[1][i + 1];
    }
    for (int i = 1; i < top_cleaner_r; ++i)
    {
        board[i][C] = board[i + 1][C];
    }
    for (int i = C; i > 1; --i)
    {
        board[top_cleaner_r][i] = board[top_cleaner_r][i - 1];
    }
    board[top_cleaner_r][2] = 0;

    //bottom clockwise
    //left
    for (int i = bottom_cleaner_r + 1; i < R; ++i)
    {
        board[i][1] = board[i + 1][1];
    }
    //bottom
    for (int i = 1; i < C; ++i)
    {
        board[R][i] = board[R][i + 1];
    }
    //right
    for (int i = R; i > bottom_cleaner_r; --i)
    {
        board[i][C] = board[i - 1][C];
    }
    //up
    for (int i = C; i > 1; --i)
    {
        board[bottom_cleaner_r][i] = board[bottom_cleaner_r][i - 1];
    }
    board[bottom_cleaner_r][2] = 0;
}

void print_board()
{
    cout << "\n";
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void Solution()
{
    while (T--)
    {
        SpreadDust();
        //print_board();
        //cout << "after cleaning\n";
        OperateCleaner();
        //print_board();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();
    cout << CalcTotalDust();

    return 0;
}