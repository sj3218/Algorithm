#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

#define BOARD_SIZE      100
#define TIME_OUT        100
#define INIT_SIZE       3

int board[BOARD_SIZE + 2][BOARD_SIZE + 2];
int Row = INIT_SIZE;
int Col = INIT_SIZE;
int r, c, k;
int game_time = 0;

void Input()
{
    cin >> r >> c >> k;
    for (int i = 1; i <= Row; ++i)
    {
        for (int j = 1; j <= Col; ++j)
        {
            cin >> board[i][j];
        }
    }
}

void CalcRow()
{
    int num;
    int max_cnt = 0;

    for (int i = 1; i <= Row; ++i)
    {
        map<int, int> m;

        for (int j = 1; j <= Col; ++j)
        {
            num = board[i][j];
            if (num == 0)
                continue;
            
            m[num]++;
        }

        vector<pair<int, int>> numbers;//count, num
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it)
        {
            numbers.push_back({ it->second, it->first });
        }

        sort(numbers.begin(), numbers.end());

        int size = numbers.size();
        int idx = 0;
        for (int j = 0; j < size; ++j)
        {
            if (idx > BOARD_SIZE)
                break;

            board[i][++idx] = numbers[j].second;
            board[i][++idx] = numbers[j].first;
        }
        for (int j = idx + 1; j <= Row; ++j)
        {
            board[i][j] = 0;
        }
        max_cnt = max(max_cnt, idx);
    }
    Col = max(Col, max_cnt);
}

void CalcCol()
{
    int num;
    int max_cnt = 0;

    for (int i = 1; i <= Col; ++i)
    {
        map<int, int> m;

        for (int j = 1; j <= Row; ++j)
        {
            num = board[j][i];
            if (num == 0)
                continue;

            m[num]++;
        }

        vector<pair<int, int>> numbers;//count, num
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); ++it)
        {
            numbers.push_back({ it->second, it->first });
        }

        sort(numbers.begin(), numbers.end());

        int size = numbers.size();
        int idx = 0;

        for (int j = 0; j < size; ++j)
        {
            if (idx > BOARD_SIZE)
                break;

            board[++idx][i] = numbers[j].second;
            board[++idx][i] = numbers[j].first;
        }
        
        for (int j = idx + 1; j <= Col; ++j)
        {
            board[j][i] = 0;
        }

        max_cnt = max(max_cnt, idx);
    }

    Row = max(Row, max_cnt);
}

bool Solution()
{
    while (true)
    {
        if (game_time > TIME_OUT)
            return false;

        if (board[r][c] == k)
            break;

        if (Row >= Col)
            CalcRow();
        else
            CalcCol();

        ++game_time;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    if (Solution())
        cout << game_time;
    else
        cout << -1;

    return 0;
}