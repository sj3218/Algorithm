#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define BOARD_SIZE      501
#define TETROMINO_SIZE  4
using namespace std;

int N, M;
int board[BOARD_SIZE][BOARD_SIZE];
bool is_visited[BOARD_SIZE][BOARD_SIZE];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

pair<int, int> blocks[4];
int answer = 0;

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > M)
        return false;
    return true;
}

int SumBlocks()
{
    int sum = 0;
    
    for (pair<int, int> next : blocks)
    {
        sum += board[next.first][next.second];
    }
    return sum;
}

void MakeTetromino(int count, int x, int y)
{
    if (count == TETROMINO_SIZE)
    {
        int sum = SumBlocks();
        answer = max(answer, sum);
        return;
    }

    int nx, ny;
    for (int i = 0; i < 4; ++i)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (!IsValid(nx, ny))
            continue;
        if (is_visited[nx][ny])
            continue;

        is_visited[nx][ny] = true;
        blocks[count] = { nx,ny };
        MakeTetromino(count + 1, nx, ny);
        blocks[count] = { 0,0 };
        is_visited[nx][ny] = false;
    }
}

void CheckExtraShape(int x, int y)
{
    int sum = board[x][y];
    int wing = 0;
    int min_adj = 1001;

    int nx, ny;
    for (int i = 0; i < 4; ++i)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (!IsValid(nx, ny))
            continue;

        ++wing;
        sum += board[nx][ny];
        min_adj = min(min_adj, board[nx][ny]);
    }

    if (wing == 4)
        sum -= min_adj;

    if (wing >= 3)
        answer = max(answer, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            blocks[0] = { i,j };

            is_visited[i][j] = true;
            MakeTetromino(1, i, j);
            is_visited[i][j] = false;
            
            CheckExtraShape(i, j);
        }
    }

    cout << answer;
    return 0;
}