#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define BOARD_SIZE 21
#define DICE_SIZE 5
#define UP      1
#define EAST    1
#define WEST    2
#define NORTH   3
#define SOUTH   4

using namespace std;

int N, M;
pair<int, int> dice_pos;
int K;
int orders[1001];
int board[BOARD_SIZE][BOARD_SIZE];
int dice[DICE_SIZE][DICE_SIZE];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= M)
        return false;
    return true;
}

void UpdateDice(int dir)
{
    int temp;

    if (dir == EAST)
    {
        temp = dice[1][3];
        for (int i = 3; i > 0; --i)
        {
            dice[1][i] = dice[1][i - 1];
        }
        dice[1][0] = temp;
        dice[3][1] = dice[1][3];
    }
    else if (dir == WEST)
    {
        temp = dice[1][0];
        for (int i = 0; i < 3; ++i)
        {
            dice[1][i] = dice[1][i + 1];
        }
        dice[1][3] = temp;
        dice[3][1] = dice[1][3];
    }
    else if (dir == NORTH)
    {
        temp = dice[0][1];
        for (int i = 0; i < 3; ++i)
        {
            dice[i][1] = dice[i + 1][1];
        }
        dice[3][1] = temp;
        dice[1][3] = dice[3][1];
    }
    else
    {
        temp = dice[3][1];
        for (int i = 3; i > 0; --i)
        {
            dice[i][1] = dice[i - 1][1];
        }
        dice[0][1] = temp;
        dice[1][3] = dice[3][1];
    }
}

void Solution()
{
    int nx, ny;
    int dir;
    for (int i = 0; i < K; ++i)
    {
        dir = orders[i] - 1;
        nx = dice_pos.first + dx[dir];
        ny = dice_pos.second + dy[dir];
        if (!IsValid(nx, ny))
            continue;

        dice_pos = { nx, ny };

        //update nums in dice
        UpdateDice(dir + 1);
        
        //update board and bottom of the dice
        if (board[nx][ny] == 0)
        {
            board[nx][ny] = dice[3][1];
        }
        else
        {
            dice[3][1] = board[nx][ny];
            dice[1][3] = board[nx][ny];
            board[nx][ny] = 0;
        }

        cout << dice[UP][UP] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> dice_pos.first >> dice_pos.second >> K;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < K; ++i)
    {
        cin >> orders[i];
    }

    Solution();

    return 0;
}