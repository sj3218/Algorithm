#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <map>

using namespace std;
#define INF 0X7FFFFFFF
int R, C;
string s;
pair<int, int> Mos;
pair<int, int> Za;
char board[26][26];
int dir_r, dir_c;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

vector<vector<pair<int, int>>> pipes = {
    {{-1, 0}, {1,0}}, {{0,-1},{0,1}}, {{-1,0},{1,0},{0,-1},{0,1}}, {{0,1}, {1,0}}, {{-1,0},{0,1}}, {{-1,0},{0,-1}}, {{0,-1}, {1,0}}
};

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > R || c > C)
        return true;
    return false;
}

void Input()
{
    cin >> R >> C;
    for (int r = 1; r <= R; ++r)
    {
        cin >> s;
        for (int c = 1; c <= C; ++c)
        {
            board[r][c] = s[c - 1];
            if (board[r][c] == 'M')
                Mos = { r,c };
            else if (board[r][c] == 'Z')
                Za = { r,c };
        }
    }
}

int FindIndex(char pipe)
{
    int idx = 0;
    if (pipe == '|')
        idx = 0;
    else if (pipe == '-')
        idx = 1;
    else if (pipe == '+')
        idx = 2;
    else if (pipe == '1')
        idx = 3;
    else if (pipe == '2')
        idx = 4;
    else if (pipe == '3')
        idx = 5;
    else if (pipe == '4')
        idx = 6;

    return idx;
}

bool FindDirection(pair<int, int> start)
{
    int cr, cc;
    char pipe;
    int pre_r, pre_c;
    int idx = 0;
    tie(pre_r, pre_c) = start;

    for (int i = 0; i < 4; ++i)
    {
        cr = start.first + dr[i];
        cc = start.second + dc[i];
        if (OutOfBound(cr, cc))
            continue;

        pipe = board[cr][cc];
        if (pipe == '.')
            continue;
        else if (pipe == '+')
        {
            dir_r = dr[i];
            dir_c = dc[i];
            return true;
        }

        idx = FindIndex(pipe);

        for (int j = 0; j < 2; ++j)
        {
            int r = cr + pipes[idx][j].first;
            int c = cc + pipes[idx][j].second;
            if (r == pre_r && c == pre_c)
            {
                dir_r = dr[i];
                dir_c = dc[i];
                return true;
            }
        }
    }

    return false;
}

void FindPipe(int r, int c)
{
    char pipe;
    int cc, cr;
    int idx;
    bool need_to_connect[4];
    fill_n(need_to_connect, 4, false);

    for (int i = 0; i < 4; ++i)
    {
        cr = r + dr[i];
        cc = c + dc[i];
        if (OutOfBound(cr, cc))
            continue;

        pipe = board[cr][cc];
        
        if (pipe == '+')
        {
            need_to_connect[i] = true;
            continue;
        }
        else if (pipe == '.')
            continue;

        idx = FindIndex(pipe);
        for (int j = 0; j < 2; ++j)
        {
            if (cr + pipes[idx][j].first == r && c == cc + pipes[idx][j].second)
            {
                need_to_connect[i] = true;
                break;
            }
        }
    }

    if (need_to_connect[0] == true)
    {
        if (need_to_connect[1] == true)
        {
            if (need_to_connect[2] == true)
                pipe = '+';
            else
                pipe = '-';
        }
        else if (need_to_connect[2] == true)
        {
            pipe = '1';
        }
        else if (need_to_connect[3])
        {
            pipe = '2';
        }
    }
    else if (need_to_connect[2])
    {
        if (need_to_connect[3])
            pipe = '|';
        else if (need_to_connect[1])
            pipe = '4';
    }
    else if (need_to_connect[1])
        if (need_to_connect[3])
            pipe = '3';

    cout << r << " " << c << " " << pipe;
}

void Follow_pipe(pair<int, int> start)
{
    int cr, cc;
    int prer, prec;
    tie(cr, cc) = start;
    tie(prer, prec) = start;
    char pipe;
    int idx = 0;

    while (true)
    {
        cr += dir_r;
        cc += dir_c;
        pipe = board[cr][cc];
        idx = FindIndex(pipe);

        if (pipe == '.')
        {
            FindPipe(cr, cc);
            return;
        }
        else if (pipe == '-' || pipe == '|' || pipe == '+')
        {
            prer = cr;
            prec = cc;

            continue;
        }

        for (int i = 0; i < 2; ++i)
        {
            if (prer != (cr + pipes[idx][i].first) && prec != (cc + pipes[idx][i].second))
            {
                tie(dir_r, dir_c) = pipes[idx][i];
                break;
            }
        }

        prer = cr;
        prec = cc;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    if (FindDirection(Mos))
    {
        Follow_pipe(Mos);
    }
    else
    {
        Follow_pipe(Za);
    }

    return 0;
}