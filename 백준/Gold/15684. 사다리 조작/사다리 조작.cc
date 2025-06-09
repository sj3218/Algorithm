#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define INF         0X7FFFFFFF
#define HEIGHT      31
#define WIDTH       11

#define MAX_COUNT   3

#define RIGHT       0
#define LEFT        1

using namespace std;

bool board[HEIGHT][WIDTH];
int row, col, row_cnt;
int answer = INF;

bool GameStart()
{
    int can_solve = true;

    for (int i = 1; i <= col; ++i)
    {
        int idx = i;
        for (int j = 1; j <= row; ++j)
        {
            if (board[j][idx])
                ++idx;
            else if (board[j][idx-1])
                --idx;
        }

        if (idx != i)
        {
            can_solve = false;
            break;
        }
    }

    return can_solve;
}

void dfs(int count, int x, int y)
{
    if (count > MAX_COUNT)
        return;
    if (count >= answer)
        return;

    if (GameStart())
    {
        answer = min(answer, count);
        if (answer == 0 || answer == 1)
        {
            return;
        }
    }

    
    for (int i = y; i <= row; ++i)
    {
        for (int j = (i == y ? x : 1); j < col; ++j)
        {
            if (board[i][j] || board[i][j - 1] || board[i][j + 1])
                continue;

            board[i][j] = true;
            dfs(count + 1, j+ 2, i);
            board[i][j] = false;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> col >> row_cnt >> row;

    int a, b;
    for (int i = 0; i < row_cnt; ++i)
    {
        cin >> a >> b;
        board[a][b] = true;
    }

    dfs(0, 1, 1);

    if (answer == INF)
        cout << -1;
    else
        cout << answer;

    return 0;
}