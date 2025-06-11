#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

#define MAX_BOARD_SIZE      51
#define CAN_MAKE_CLOUD_     2
#define MAX_STREET          50

int board_size, order_cnt;
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
vector<pair<int, int>> orders;
vector<pair<int, int>> clouds_pos;
bool has_cloud[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int total_amount = 0;

int dr[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dc[9] = { 0,-1,-1,0,1,1,1,0,-1 };

void print_has_cloud()
{
    cout << "\nclouds\n";

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cout << has_cloud[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

void print_water_board()
{
    cout << "\nwater board\n";

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

void Input()
{
    cin >> board_size >> order_cnt;

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cin >> board[i][j];
        }
    }

    int d, s;
    for (int i = 0; i < order_cnt; ++i)
    {
        cin >> d >> s;
        orders.push_back({ d,s });
    }
}

bool IsValid(int r, int c)
{
    if (r <= 0 || c <= 0 || r > board_size || c > board_size)
        return false;
    return true;
}

void MoveClouds(int d, int s)
{
    int size = clouds_pos.size();
    int nr, nc;

    for (int i = 0; i < size; ++i)
    {
        nr = clouds_pos[i].first + dr[d] * s;
        nc = clouds_pos[i].second + dc[d] * s;

        if (nr < 0)
        {
            while (nr < 0)
            {
                nr += board_size;
            }
        }
        else if(nr > 0)
            nr %= board_size;
        if (nr == 0)
            nr = board_size;

        if (nc < 0)
        {
            while (nc < 0)
            {
                nc += board_size;
            }
        }
        else if (nc > 0)
            nc %= board_size;
        if (nc == 0)
            nc = board_size;

        clouds_pos[i] = { nr,nc };
    }

    fill_n(&has_cloud[0][0], MAX_BOARD_SIZE * MAX_BOARD_SIZE, false);
    for (pair<int, int> cloud : clouds_pos)
    {
        has_cloud[cloud.first][cloud.second] = true;
    }
}

void Rainning()
{
    int r, c;
    for (pair<int, int> cloud : clouds_pos)
    {
        tie(r, c) = cloud;
        board[r][c]++;
    }
}

void WaterMagic()
{
    int r, c;
    int nr, nc;
    int cnt = 0;
    for (pair<int, int> cloud : clouds_pos)
    {
        cnt = 0;
        tie(r, c) = cloud;
        for (int i = 2; i <= 8; i += 2)
        {
            nr = r + dr[i];
            nc = c + dc[i];

            if (!IsValid(nr, nc))
                continue;
            if (board[nr][nc] > 0)
                ++cnt;
        }
        board[r][c] += cnt;
    }
}

void MakeClouds()
{
    clouds_pos.clear();
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (has_cloud[i][j])
            {
                has_cloud[i][j] = false;
                continue;
            }

            if (board[i][j] < CAN_MAKE_CLOUD_)
                continue;

            clouds_pos.push_back({ i,j });
            has_cloud[i][j] = true;
            board[i][j] -= CAN_MAKE_CLOUD_;
        }
    }
}

int CalculateTotalWater()
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


void Solution()
{
    has_cloud[board_size][1] = true;
    has_cloud[board_size][2] = true;
    has_cloud[board_size - 1][1] = true;
    has_cloud[board_size - 1][2] = true;

    clouds_pos.push_back({ board_size, 1 });
    clouds_pos.push_back({ board_size, 2 });
    clouds_pos.push_back({ board_size-1, 1 });
    clouds_pos.push_back({ board_size-1, 2 });

    for (pair<int, int> order : orders)
    {
        MoveClouds(order.first, order.second);
        Rainning();
        WaterMagic();        
        MakeClouds();
    }

    total_amount = CalculateTotalWater();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();
    cout << total_amount;

    return 0;
}