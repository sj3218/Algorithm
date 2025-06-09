#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define CURVE_COUNT     21
#define BOARD_SIZE      101
using namespace std;

bool board[BOARD_SIZE][BOARD_SIZE];
int curve_cnt;
int x, y, dir, gen;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,-1,0,1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> curve_cnt;

    int new_dir, size;
    int nx, ny;
    while (curve_cnt--)
    {
        cin >> x >> y >> dir >> gen;

        board[y][x] = true;
        vector<int> curves;
        curves.push_back(dir);

        nx = x;
        ny = y;
        size = 0;

        while (gen--)
        {
            size = curves.size();
            for (int i = size - 1; i >= 0; --i)
            {
                new_dir = curves[i] + 1;
                new_dir %= 4;
                curves.push_back(new_dir);
            }
        }

        for (int idx : curves)
        {
            nx += dx[idx];
            ny += dy[idx];
            board[ny][nx] = true;
        }
    }

    int answer = 0;
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1])
                ++answer;
        }
    }

    cout << answer;
    return 0;
}