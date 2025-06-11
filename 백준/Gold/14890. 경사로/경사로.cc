#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
#define BOARD_SIZE          101

int N, L;
int board[BOARD_SIZE][BOARD_SIZE];
bool has_stair[BOARD_SIZE];

bool CanMakeStreet(int id, bool is_col)
{
    int cnt = 1;
    int pre_num, curr_num, diff;
    if (is_col)
        pre_num = board[1][id];
    else
        pre_num = board[id][1];

    for (int i = 2; i <= N; ++i)
    {
        if (is_col)
            curr_num = board[i][id];
        else
            curr_num = board[id][i];

        if (curr_num == pre_num)
        {
            ++cnt;
            continue;
        }
        
        diff = abs(curr_num - pre_num);
        if(diff > 1)
            return false;

        if (curr_num > pre_num)
        {
            if (cnt < L)
                return false;
            if (has_stair[i-1])
                return false;
            has_stair[i - 1] = true;
            cnt = 1;
        }
        else
        {
            int num;
            int j;
            for (j = i+1; j < i + L; ++j)
            {
                if (j > N)
                    return false;

                if (is_col)
                    num = board[j][id];
                else
                    num = board[id][j];

                
                if (num != curr_num)
                    return false;
            }
            
            has_stair[i] = true;
            has_stair[j - 1] = true;
            i = j-1;
            cnt = 0;
        }

        pre_num = curr_num;
    }

    return true;
}

int CountRowLines()
{
    int cnt = 0;
    for (int r = 1; r <= N; ++r)
    {
        fill_n(has_stair, BOARD_SIZE, false);
        if (CanMakeStreet(r, false))
            ++cnt;
    }
    return cnt;
}

int CountColLines()
{
    int cnt = 0;
    for (int c = 1; c <= N; ++c)
    {
        fill_n(has_stair, BOARD_SIZE, false);
        if (CanMakeStreet(c, true))
            ++cnt;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> L;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[i][j];
        }
    }

    int total_streets = 0;
    total_streets += CountRowLines();
    total_streets += CountColLines();

    cout << total_streets;

    return 0;
}