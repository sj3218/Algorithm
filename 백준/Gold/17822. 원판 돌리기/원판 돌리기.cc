#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

#define MAX_BOARD_SIZE      51
#define CLOCKWISE           0
#define COUNTER_CLOCKWISE   1
#define EMPTY               -1

int board_size, num_count, rotate_cnt;//N,M,T
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
vector<tuple<int, int, int>> rotate_info; //x,d,k
bool is_visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
vector<pair<int, int>> near_values;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

void Input()
{
    cin >> board_size >> num_count >> rotate_cnt;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= num_count; ++j)
        {
            cin >> board[i][j];
        }
    }

    int x, d, k;
    for (int i = 0; i < rotate_cnt; ++i)
    {
        cin >> x >> d >> k;
        rotate_info.push_back({ x,d,k });
    }
}

void RotateClockwise(int id, int size)
{
    int temp[MAX_BOARD_SIZE];
    
    if (size >= num_count)
    {
        size %= num_count;
        if (size == 0)
            return;
    }

    int idx = num_count - size + 1;
    for (int c = 1; c <= num_count; ++c)
    {
        temp[c] = board[id][idx++];
        if (idx > num_count)
            idx = 1;
    }

    //copy
    for (int c = 1; c <= num_count; ++c)
    {
        board[id][c] = temp[c];
    }
}

void RotateCounterClockwise(int id, int size)
{
    int temp[MAX_BOARD_SIZE];

    if (size >= num_count)
    {
        size %= num_count;
        if (size == 0)
            return;
    }

    int idx = size + 1;
    for (int c = 1; c <= num_count; ++c)
    {
        temp[c] = board[id][idx++];
        if (idx > num_count)
            idx = 1;
    }

    //copy
    for (int c = 1; c <= num_count; ++c)
    {
        board[id][c] = temp[c];
    }
}

void RotateBoard(int id, int dir, int size)
{
    for (int i = 1 * id; i <= board_size; i += id)
    {
        if (dir == CLOCKWISE)
        {
            RotateClockwise(i, size);
        }
        else
        {
            RotateCounterClockwise(i, size);
        }
    }
}

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > board_size || c > num_count)
        return true;
    return false;
}

void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({ r,c });
    is_visited[r][c] = true;
    int num = board[r][c];
    bool has_near = false;

    int cr, cc, nr, nc;
    while (!q.empty())
    {
        cr = q.front().first;
        cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];

            if (nc == 0)
                nc = num_count;
            else if (nc > num_count)
                nc = 1;

            if (OutOfBound(nr, nc) || is_visited[nr][nc])
                continue;

            if (board[nr][nc] != num || board[nr][nc] == EMPTY)
                continue;

            is_visited[nr][nc] = true;
            q.push({ nr,nc });
            near_values.push_back({ nr,nc });
            has_near = true;
        }
    }

    if (has_near)
        near_values.push_back({ r,c });
}

void FindNearValues()
{
    fill_n(&is_visited[0][0], MAX_BOARD_SIZE * MAX_BOARD_SIZE, false);

    for (int r = 1; r <= board_size; ++r)
    {
        for (int c = 1; c <= num_count; ++c)
        {
            if (is_visited[r][c])
                continue;
            if (board[r][c] == EMPTY)
                continue;

            bfs(r, c);
        }
    }
}

//sum, cnt
pair<int,int> SumTotalValues()
{
    int sum = 0;
    int cnt = 0;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= num_count; ++j)
        {
            if (board[i][j] == EMPTY)
                continue;
            sum += board[i][j];
            cnt++;
        }
    }
    return { sum, cnt };
}

void print_board()
{

    cout << "\n";
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= num_count; ++j)
        {
            if (board[i][j] == EMPTY)
                cout << ". ";
            else
                cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

void Solution()
{
    int x, d, k;
    for (tuple<int, int, int> info : rotate_info)
    {
        tie(x, d, k) = info;
        RotateBoard(x, d, k);
       // print_board();

        FindNearValues();

        if (near_values.size() == 0)
        {
            //calculate values
            pair<int, int> sum = SumTotalValues();
            if (sum.second == 0)
                continue;

            float avg = (float)sum.first / sum.second;

            for (int i = 1; i <= board_size; ++i)
            {
                for (int j = 1; j <= num_count; ++j)
                {
                    if (board[i][j] == EMPTY)
                        continue;
                    
                    if (board[i][j] > avg)
                    {
                        board[i][j]--;
                    }
                    else if(board[i][j] < avg)
                    {
                        board[i][j]++;
                    }
                }
            }
        }
        else
        {
            //delete near values
            int r, c;
            for (pair<int, int> value : near_values)
            {
                tie(r, c) = value;
                board[r][c] = EMPTY;
            }

            near_values.clear();
        }

        //print_board();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();
    cout << SumTotalValues().first;

    return 0;
}