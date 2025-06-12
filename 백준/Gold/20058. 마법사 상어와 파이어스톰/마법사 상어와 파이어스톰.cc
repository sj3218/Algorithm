#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
#include <cmath>

using namespace std;

#define MAX_BOARD_SIZE      65
#define MAX_MAGIC_COUNT     1001
#define MELTING_CUT_LINE    3

int N, magic_cnt;
int board_size;
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int layers[MAX_MAGIC_COUNT];
bool is_visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > board_size || c > board_size)
        return true;
    return false;
}

int bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({ r,c });
    is_visited[r][c] = true;

    int cr, cc, nr, nc;
    int cnt = 1;
    while (!q.empty())
    {
        cr = q.front().first;
        cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            nr = cr + dx[i];
            nc = cc + dy[i];
            if (OutOfBound(nr, nc))
                continue;
            if (is_visited[nr][nc])
                continue;
            if (board[nr][nc] == 0)
                continue;

            is_visited[nr][nc] = true;
            q.push({ nr,nc });
            cnt++;
        }
    }
    return cnt;
}

int FindBiggestIceberg()
{
    int max_ice_cnt = 0;
    int temp;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (is_visited[i][j])
                continue;
            if (board[i][j] == 0)
                continue;

            temp = bfs(i, j);
            max_ice_cnt = max(max_ice_cnt, temp);
        }
    }
    return max_ice_cnt;
}

int CalculateTotalIce()
{
    int amount = 0;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            amount += board[i][j];
        }
    }
    return amount;
}

void Input()
{
    cin >> N >> magic_cnt;
    board_size = pow(2, N);
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < magic_cnt; ++i)
    {
        cin >> layers[i];
    }
}

void RotateBoard(int layer)
{
    layer = pow(2, layer);

    int size = board_size / layer;
    int temp[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    fill_n(&temp[0][0], MAX_BOARD_SIZE * MAX_BOARD_SIZE, 0);

    int x, y, r_idx, c_idx;
    for (int i = 0; i < size; ++i)
    {
        x = 1 + i * layer;

        for (int j = 0; j < size; ++j)
        {
            y = 1 + j * layer;
            c_idx = y + layer - 1;

            //rotate
            for (int r = x; r < x + layer; ++r)
            {
                r_idx = x;
                for (int c = y; c < y + layer; ++c)
                {
                    temp[r_idx++][c_idx] = board[r][c];
                }
                --c_idx;
            }
        }
    }

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            board[i][j] = temp[i][j];
        }
    }
}

void MeltingIce()
{
    int temp[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    fill_n(&temp[0][0], MAX_BOARD_SIZE * MAX_BOARD_SIZE, 0);

    int r, c, cnt;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (board[i][j] == 0)
                continue;

            cnt = 0;
            for (int d = 0; d < 4; ++d)
            {
                r = i + dx[d];
                c = j + dy[d];
                if (OutOfBound(r, c))
                    continue;
                if (board[r][c] > 0)
                    ++cnt;
            }

            if (cnt < MELTING_CUT_LINE)
                temp[i][j] = board[i][j] - 1;
            else
                temp[i][j] = board[i][j];
        }
    }

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            board[i][j] = temp[i][j];
        }
    }
}

void print_board()
{
    cout << "\n";
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cout << board[i][j]<<" ";
        }
        cout << "\n";
    }
}

void Solution()
{
    int layer;
    for (int i = 0; i < magic_cnt; ++i)
    {
        layer = layers[i];
        RotateBoard(layer);

        /*cout << "after rotate\n";
        print_board();*/

        MeltingIce();

        /*cout << "after melting\n";
        print_board();*/
    }

    //print answer
    cout << CalculateTotalIce()<<"\n";
    cout << FindBiggestIceberg();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();

    return 0;
}