#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define MAX_BOARD_SIZE      21
#define BLACK               -1
#define RAINBOW             0
#define EMPTY               100

int board_size, color_cnt; //N,M
int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int find_cnt;
vector<pair<int, int>> find_blocks;
bool is_visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int gain_score = 0;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > board_size || c > board_size)
        return true;
    return false;
}

void print_board()
{
    cout << "\n";
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (board[i][j] == EMPTY)
            {
                cout << ". ";
                continue;
            }
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<pair<int, int>> bfs(int r, int c)
{
    vector<pair<int, int>> blocks;
    queue<pair<int, int>> q;
    q.push({ r,c });
    is_visited[r][c] = true;
    blocks.push_back({ r,c });
    int num = board[r][c];

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

            if (OutOfBound(nr, nc) || is_visited[nr][nc])
                continue;

            if (board[nr][nc] == BLACK || board[nr][nc] == EMPTY)
                continue;

            if (board[nr][nc] != num && board[nr][nc]!=RAINBOW)
                continue;

            is_visited[nr][nc] = true;
            q.push({ nr,nc });
            blocks.push_back({ nr,nc });
        }
    }

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (board[i][j] == RAINBOW && is_visited[i][j])
                is_visited[i][j] = false;
        }
    }
    return blocks;
}

void FindBlockSets()
{
    fill_n(&is_visited[0][0], MAX_BOARD_SIZE * MAX_BOARD_SIZE, false);
    int cnt;
    int rainbow_cnt = 0;
    int curr_r, curr_c;
    vector<pair<int, int>> temp;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (board[i][j] == RAINBOW || board[i][j] == BLACK || board[i][j] ==EMPTY)
                continue;
            if (is_visited[i][j])
                continue;

            temp = bfs(i, j);
            cnt = temp.size();
            if (cnt < find_cnt)
            {
                continue;
            }
            else if (cnt == find_cnt)
            {
                int temp_rainbow_cnt = 0;
                int r, c;
                for (pair<int, int> block : temp)
                {
                    tie(r, c) = block;
                    if (board[r][c] == RAINBOW)
                        ++temp_rainbow_cnt;
                }

                if (temp_rainbow_cnt < rainbow_cnt)
                    continue;
                else if (temp_rainbow_cnt == rainbow_cnt)
                {
                    int temp_r, temp_c;
                    temp_r = temp[0].first;
                    temp_c = temp[0].second;
                    if (temp_r < curr_r)
                        continue;
                    else if (temp_r == curr_r)
                    {
                        if (temp_c < curr_c)
                        {
                            continue;
                        }
                    }
                }

            }

            find_cnt = cnt;
            find_blocks = temp;
            int r, c;
            rainbow_cnt = 0;
            for (pair<int, int> block : temp)
            {
                tie(r, c) = block;
                if (board[r][c] == RAINBOW)
                    ++rainbow_cnt;
            }
            curr_r = find_blocks[0].first;
            curr_c = find_blocks[0].second;
        }
    }
}

void DeleteBlockSets()
{
    int r, c;
    for (pair<int, int>block : find_blocks)
    {
        tie(r, c) = block;
        board[r][c] = EMPTY;
    }

    gain_score += find_cnt * find_cnt;

    find_cnt = 0;
    find_blocks.clear();
}

void Gravity()
{
    int num;
    int floor_idx = -1;
    for (int c = 1; c <= board_size; ++c)
    {
        floor_idx = -1;
        for (int r = board_size; r > 0; --r)
        {
            num = board[r][c];

            if (num == EMPTY && floor_idx == -1)
            {
                floor_idx = r;
            }
            else if (RAINBOW <= num && num <= color_cnt)
            {
                if (floor_idx != -1)
                {
                    board[floor_idx][c] = num;
                    floor_idx--;
                    board[r][c] = EMPTY;
                }
            }
            else if (num == BLACK)
            {
                floor_idx = -1;
            }
        }
    }
}

void RotateCounterClockwise()
{
    int idx = 1;
    int temp[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
    for (int c = board_size; c > 0; --c)
    {
        for (int r = 1; r <= board_size; ++r)
        {
            temp[idx][r] = board[r][c];
        }
        ++idx;
    }

    for (int r = 1; r <= board_size; ++r)
    {
        for (int c = 1; c <= board_size; ++c)
        {
            board[r][c] = temp[r][c];
        }
    }
}

void Input()
{
    cin >> board_size >> color_cnt;

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cin >> board[i][j];
        }
    }
}

void Solution()
{
    while (true)
    {
        FindBlockSets();

        if (find_cnt <= 1)
            break;

        DeleteBlockSets();

        Gravity();
        //print_board();
        RotateCounterClockwise();
        //print_board();
        Gravity();
        //print_board();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();
    cout << gain_score;
    return 0;
}