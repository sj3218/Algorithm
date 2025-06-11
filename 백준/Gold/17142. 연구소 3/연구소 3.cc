#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
#define MAX_BOARD_SIZE          51
#define MAX_VIRUS_SIZE          11
#define EMPTY                   0
#define WALL                    1
#define UNACTIVATED_VIRUS       2
#define INF                     0X7FFFFFFF
#define FAIL_SPREAD_VIRUS       -1

int board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
vector<pair<int, int>> virus_pos;
bool selected_virus[MAX_BOARD_SIZE * MAX_BOARD_SIZE];

int board_size, can_activate_virus_cnt;
int virus_cnt;
int answer = INF;

int is_visited[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0,0 };

void Input()
{
    cin >> board_size >> can_activate_virus_cnt;

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == UNACTIVATED_VIRUS)
            {
                virus_pos.push_back({ i,j });
            }
        }
    }
    virus_cnt = virus_pos.size();
}

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > board_size || y > board_size)
        return false;
    return true;
}

bool CanSpreadAllArea()
{
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (is_visited[i][j] == -1 && board[i][j] == EMPTY)
            {
                return false;
            }
        }
    }
    return true;
}
int bfs()
{
    fill_n(&is_visited[0][0], MAX_BOARD_SIZE * MAX_BOARD_SIZE, -1);

    queue<pair<int, int>> q;
    int x, y;
    int nx, ny;
    int max_time = 0;
    int curr_time;
    for (int i = 0; i < virus_cnt; ++i)
    {
        if (selected_virus[i])
        {
            tie(x, y) = virus_pos[i];
            q.push({x,y});
            is_visited[x][y] = 0;
        }
    }

    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        curr_time = is_visited[x][y];

        for (int i = 0; i < 4; ++i)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (!IsValid(nx, ny) || board[nx][ny] == WALL)
                continue;

            if (is_visited[nx][ny] != -1)
                continue;

            if (board[nx][ny] != UNACTIVATED_VIRUS)
            {
                max_time = max(max_time, curr_time+1);
            }
            
            is_visited[nx][ny] = curr_time + 1;
            q.push({ nx,ny });
        }
    }

    if (!CanSpreadAllArea())
        max_time = INF;

    return max_time;
}

void print_virus_time()
{
    cout << "\n";
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (is_visited[i][j] == -1)
                cout << "- ";
            else
                cout << is_visited[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

void SelectVirus(int count, int start_idx)
{
    if (count == can_activate_virus_cnt)
    {
        answer = min(answer, bfs());
        //print_virus_time();
        return;
    }

    for (int i = start_idx; i < virus_cnt; ++i)
    {
        if (selected_virus[i])
            continue;

        selected_virus[i] = true;
        SelectVirus(count + 1, i + 1);
        selected_virus[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    SelectVirus(0, 0);
    if (answer == INF)
        cout << FAIL_SPREAD_VIRUS;
    else
        cout << answer;

    return 0;
}