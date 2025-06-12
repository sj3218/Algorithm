#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_BOARD_SIZE  51
#define MEASURE_AMOUNT  5

int board_size, fire_balls_cnt, order_cnt;
vector<tuple<int, int, int>> board[MAX_BOARD_SIZE][MAX_BOARD_SIZE]; //m,s,d
int r, c, m, d, s;

int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };

void Input()
{
    cin >> board_size >> fire_balls_cnt >> order_cnt;
    for (int i = 0; i < fire_balls_cnt; ++i)
    {
        cin >> r >> c >> m >> s >> d;
        board[r][c].push_back({ m,s,d });
    }
}

void MoveFireBalls()
{
    int nr, nc;
    vector<tuple<int, int, int>> temp[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

    int id = 0;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (board[i][j].size() == 0)
                continue;

            for (tuple<int, int, int> fire : board[i][j])
            {
                tie(m, s, d) = fire;

                nr = i + dr[d] * s;
                nc = j + dc[d] * s;

                while (nr < 0)
                    nr += board_size;
                if (nr > board_size)
                    nr %= board_size;
                if (nr == 0)
                    nr = board_size;

                while (nc < 0)
                    nc += board_size;
                if (nc > board_size)
                    nc %= board_size;
                if (nc == 0)
                    nc = board_size;

                temp[nr][nc].push_back({ m,s,d });
            }
        }
    }
    
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            swap(temp[i][j], board[i][j]);
        }
    }
}

void CalculateFireBall(int r, int c, int count)
{
    int total_amount = 0;
    int total_speed = 0;
    bool are_same_direction = true;
    bool is_odd = true;

    tie(m, s, d) = board[r][c][0];
    if (d % 2 == 0)
        is_odd = false;

    for (tuple<int, int, int> fire : board[r][c])
    {
        tie(m, s, d) = fire;
        if (are_same_direction)
            if (is_odd != (d % 2 != 0))
                are_same_direction = false;

        total_amount += m;
        total_speed += s;
    }

    int new_m, new_s, start_idx;
    new_m = total_amount / MEASURE_AMOUNT;
    new_s = total_speed / count;

    board[r][c].clear();
    if (new_m == 0)
    {
        return;
    }

    if (are_same_direction)
        start_idx = 0;
    else
        start_idx = 1;

    for (int i = start_idx; i < 8; i += 2)
    {
        board[r][c].push_back({ new_m,new_s,i });
    }
}

void Solution()
{
    int cnt;
    while (order_cnt--)
    {
        MoveFireBalls();

        for (int i = 1; i <= board_size; ++i)
        {
            for (int j = 1; j <= board_size; ++j)
            {
                cnt = board[i][j].size();
                if(cnt >= 2)
                    CalculateFireBall(i, j, cnt);
            }
        }
    }
}

int CalculateTotalAmount()
{
    int amount = 0;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            for (tuple<int, int, int> fire : board[i][j])
                amount += get<0>(fire); //m
        }
    }
    return amount;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();
    cout << CalculateTotalAmount();

    return 0;
}