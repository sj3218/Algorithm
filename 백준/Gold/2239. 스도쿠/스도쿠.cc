#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include<tuple>
using namespace std;
string s;
int board[10][10];
bool is_visited_row[10][10];
bool is_visited_col[10][10];
bool is_visited_box[3][3][10];

pair<int, int> idx_to_box(int r, int c)
{
    //1,2,3 -> 0
    //4,5,6 -> 1
    //7,8,9 -> 2
    int nr = r / 3;
    int nc = c / 3;
    if (r % 3 == 0)
        nr--;
    if (c % 3 == 0)
        nc--;

    return { nr,nc };
}
bool dfs(int r, int c)
{
    if (c == 10)
    {
        r++;
        c = 1;
    }

    if (r == 10 && c == 1)
        return true;

    if (board[r][c] != 0)
    {
        if (dfs(r, c + 1))
            return true;
        else
            return false;
    }

    int nr, nc;
    tie(nr, nc) = idx_to_box(r, c);

    for (int i = 1; i <= 9; ++i)
    {
        if (is_visited_row[r][i])
            continue;
        if (is_visited_col[c][i])
            continue;
        if (is_visited_box[nr][nc][i])
            continue;

        is_visited_col[c][i] = true;
        is_visited_row[r][i] = true;
        is_visited_box[nr][nc][i] = true;
        board[r][c] = i;
        
        if (dfs(r, c + 1))
            return true;

        is_visited_col[c][i] = false;
        is_visited_row[r][i] = false;
        is_visited_box[nr][nc][i] = false;
        board[r][c] = 0;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int nr, nc;
    for (int i = 1; i <= 9; ++i)
    {
        cin >> s;
        for (int j = 1; j <= 9; ++j)
        {
            board[i][j] = s[j-1] - '0';

            if (board[i][j] != 0)
            {
                is_visited_col[j][board[i][j]] = true;
                is_visited_row[i][board[i][j]] = true;
                tie(nr, nc) = idx_to_box(i, j);
                is_visited_box[nr][nc][board[i][j]] = true;
            }
        }
    }

    dfs(1, 1);

    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
        {
            cout << board[i][j];
        }
        cout << "\n";
    }
    return 0;
}
