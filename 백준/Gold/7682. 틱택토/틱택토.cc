#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
string s;
const int X = 1;
const int O = 2;
const int EMPTY = 0;
int board[3][3];
int x_cnt, o_cnt;

void Init()
{
    int idx = 0;
    x_cnt = 0;
    o_cnt = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (s[idx] == 'O')
            {
                ++o_cnt;
                board[i][j] = O;
            }
            else if (s[idx] == 'X')
            {
                ++x_cnt;
                board[i][j] = X;
            }
            else
                board[i][j] = EMPTY;
            ++idx;
        }
    }
}

bool IsValid(const int type)
{
    //col
    for (int r = 0; r < 3; ++r)
    {
        bool is_valid = true;
        for (int c = 0; c < 3; ++c)
        {
            if (board[r][c] != type)
            {
                is_valid = false;
                break;
            }
        }

        if (is_valid)
            return true;
    }

    //row
    for (int c = 0; c < 3; ++c)
    {
        bool is_valid = true;
        for (int r = 0; r < 3; ++r)
        {
            if (board[r][c] != type)
            {
                is_valid = false;
                break;
            }
        }

        if (is_valid)
            return true;
    }

    //diagonal
    bool is_valid = true;
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][i] != type)
        {
            is_valid = false;
            break;
        }
    }
    if (is_valid)
        return true;

    is_valid = true;
    for (int i = 0, j = 2; i < 3; ++i, --j)
    {
        if (board[i][j] != type)
        {
            is_valid = false;
            break;
        }
    }
    if (is_valid)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    bool is_valid;
    bool x_is_valid = false;
    bool o_is_valid = false;

    while (true)
    {
        cin >> s;

        if (s == "end")
            break;

        Init();
        is_valid = true;
        if (o_cnt > x_cnt || x_cnt - o_cnt >= 2)
        {
            cout << "invalid\n";
            continue;
        }

        x_is_valid = IsValid(X);
        o_is_valid = IsValid(O);

        if (x_is_valid && o_is_valid)
            is_valid = false;
        else if (x_is_valid)
        {
            if (o_cnt == x_cnt)
                is_valid = false;
        }
        else if (o_is_valid)
        {
            if (o_cnt < x_cnt)
                is_valid = false;
            if (o_cnt + x_cnt == 0)
                is_valid = false;
        }
        else if (x_cnt + o_cnt == 9)
            is_valid = true;
        else
            is_valid = false;

        if (is_valid)
            cout << "valid\n";
        else
            cout << "invalid\n";
    }

    return 0;
}