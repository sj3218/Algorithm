#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define GAME_END        1000
#define WHITE_BOARD     0
#define RED_BOARD       1
#define BLUE_BOARD      2
#define OVER_KNIGHTS    4

using namespace std;

int N, K;
int board[13][13];
int game_cnt = 0;

struct Knight
{
    int x;
    int y;
    int dir;
}knights[11];

vector<int> knights_in_board[13][13];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

void Input()
{
    fill_n(&board[0][0], 13 * 13, -1);

    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[i][j];
        }
    }

    int r, c, d;
    for (int i = 1; i <= K; ++i)
    {
        cin >> r >> c >> d;
        knights[i] = { r, c, d };
        knights_in_board[r][c].push_back(i);
    }
}

void ChangeDirection(int idx)
{
    int dir = knights[idx].dir;
    if (dir == 1)
    {
        dir = 2;
    }
    else if (dir == 2)
    {
        dir = 1;
    }
    else if (dir == 3)
    {
        dir = 4;
    }
    else
        dir = 3;

    knights[idx].dir = dir;
}

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > N)
        return false;
    return true;
}

void MoveKnight(int idx)
{
    Knight knight = knights[idx];

    int nx = knight.x + dx[knight.dir - 1];
    int ny = knight.y + dy[knight.dir - 1];

    if (!IsValid(nx, ny) || board[nx][ny] == BLUE_BOARD)
    {
        ChangeDirection(idx);

        knight = knights[idx];
        nx = knight.x + dx[knight.dir - 1];
        ny = knight.y + dy[knight.dir - 1];
        if (IsValid(nx, ny) && board[nx][ny] != BLUE_BOARD)
        {
            //MoveKnight(idx);
            if (board[nx][ny] == WHITE_BOARD)
            {
                int curr_idx;
                int find_idx = find(knights_in_board[knight.x][knight.y].begin(), knights_in_board[knight.x][knight.y].end(), idx) - knights_in_board[knight.x][knight.y].begin();
                int cur_knight_size = knights_in_board[knight.x][knight.y].size();

                for (int i = find_idx; i < cur_knight_size; ++i)
                {
                    curr_idx = knights_in_board[knight.x][knight.y][i];
                    knights_in_board[nx][ny].push_back(curr_idx);
                    knights[curr_idx].x = nx;
                    knights[curr_idx].y = ny;
                }

                knights_in_board[knight.x][knight.y].erase(knights_in_board[knight.x][knight.y].begin() + find_idx, knights_in_board[knight.x][knight.y].end());
            }
            else if (board[nx][ny] == RED_BOARD)
            {
                int curr_idx;
                int find_idx = find(knights_in_board[knight.x][knight.y].begin(), knights_in_board[knight.x][knight.y].end(), idx) - knights_in_board[knight.x][knight.y].begin();
                int cur_knight_size = knights_in_board[knight.x][knight.y].size();
                for (int i = cur_knight_size - 1; i >= find_idx; --i)
                {
                    curr_idx = knights_in_board[knight.x][knight.y][i];
                    knights_in_board[nx][ny].push_back(curr_idx);
                    knights[curr_idx].x = nx;
                    knights[curr_idx].y = ny;
                    knights_in_board[knight.x][knight.y].pop_back();
                }
            }
        }
    }
    else if (board[nx][ny] == WHITE_BOARD)
    {
        int curr_idx;
        int find_idx = find(knights_in_board[knight.x][knight.y].begin(), knights_in_board[knight.x][knight.y].end(), idx) - knights_in_board[knight.x][knight.y].begin();
        int cur_knight_size = knights_in_board[knight.x][knight.y].size();

        for (int i = find_idx; i < cur_knight_size; ++i)
        {
            curr_idx = knights_in_board[knight.x][knight.y][i];
            knights_in_board[nx][ny].push_back(curr_idx);
            knights[curr_idx].x = nx;
            knights[curr_idx].y = ny;
        }

        knights_in_board[knight.x][knight.y].erase(knights_in_board[knight.x][knight.y].begin() + find_idx, knights_in_board[knight.x][knight.y].end());
    }
    else if (board[nx][ny] == RED_BOARD)
    {
        int curr_idx;
        int find_idx = find(knights_in_board[knight.x][knight.y].begin(), knights_in_board[knight.x][knight.y].end(), idx) - knights_in_board[knight.x][knight.y].begin();
        int cur_knight_size = knights_in_board[knight.x][knight.y].size();
        for (int i = cur_knight_size - 1; i >= find_idx; --i)
        {
            curr_idx = knights_in_board[knight.x][knight.y][i];
            knights_in_board[nx][ny].push_back(curr_idx);
            knights[curr_idx].x = nx;
            knights[curr_idx].y = ny;
            knights_in_board[knight.x][knight.y].pop_back();
        }
    }
}

void print_knights_in_board()
{
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << knights_in_board[i][j].size() << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Solution()
{
    Input();

    bool has_over_knight = false;
    int cx, cy;
    while (game_cnt <= GAME_END)
    {
        if (has_over_knight)
            break;

        for (int i = 1; i <= K; ++i)
        {
            MoveKnight(i);
            
            cx = knights[i].x;
            cy = knights[i].y;
            if (knights_in_board[cx][cy].size() >= OVER_KNIGHTS)
            {
                has_over_knight = true;
                break;
            }
            //print_knights_in_board();
        }
        ++game_cnt;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Solution();

    if (game_cnt > GAME_END)
        cout << -1;
    else
        cout << game_cnt;

    return 0;
}