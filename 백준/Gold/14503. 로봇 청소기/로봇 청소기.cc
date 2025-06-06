#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define BOARD_SIZE 51
#define WALL        1
#define EMPTY       0
#define CLEAN       2

using namespace std;

int N, M;
pair<int, int> robot_pos;
int dir;
int board[BOARD_SIZE][BOARD_SIZE];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int clean_room_cnt = 0;

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= M)
        return false;
    return true;
}

bool ThereAreAllCleanRooms(int x, int y)
{
    int nx, ny;
    bool all_clean = true;
    for (int i = 0; i < 4; ++i)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (!IsValid(nx, ny))
            continue;
        if (board[nx][ny] == WALL)
            continue;

        if (board[nx][ny] == EMPTY)
        {
            all_clean = false;
            break;
        }
    }
    return all_clean;
}

void MoveRobot(int& x, int& y)
{
    int nx, ny;
    int new_dir = dir;
    for (int i = 0; i < 4; ++i)
    {
        --new_dir;

        if (new_dir < 0)
            new_dir = 3;

        nx = x + dx[new_dir];
        ny = y + dy[new_dir];
        if (!IsValid(nx, ny) || board[nx][ny] == WALL || board[nx][ny] == CLEAN)
            continue;

        dir = new_dir;
        x = nx;
        y = ny;
        break;
    }
}

void Solution()
{
    int x, y;
    x = robot_pos.first;
    y = robot_pos.second;

    while (true)
    {
        //1. clean the current room
        if (board[x][y] == EMPTY)
        {
            ++clean_room_cnt;
            board[x][y] = CLEAN;
        }

        //2. if all of the rooms are clean
        if (ThereAreAllCleanRooms(x, y))
        {
            int dir_idx = (dir + 2) % 4;
            int nx = x + dx[dir_idx];
            int ny = y + dy[dir_idx];
            if (!IsValid(nx, ny) || board[nx][ny] == WALL)
                break;
            else
            {
                x = nx;
                y = ny;
            }
        }
        else //3. if there is not cleaning room
        {
            MoveRobot(x, y);
        }
    }

    cout << clean_room_cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cin >> robot_pos.first >> robot_pos.second >> dir;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }

    Solution();
    
    return 0;
}