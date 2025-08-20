#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

bool board[10][10][20];//r,c,time
string s;

int dr[9] = { -1,-1,-1,0,0,1,1,1,0 };
int dc[9] = { -1,0,1,-1,1,-1,0,1,0 };

bool is_visited[10][10][20];//r,c,time


void Input()
{
    for (int i = 1; i <= 8; ++i)
    {
        cin >> s;
        for (int j = 1; j <= 8; ++j)
        {
            if (s[j - 1] == '.')
                board[i][j][0] = true;
            else
                board[i][j][0] = false;
        }
    }

    for (int i = 1; i <= 19; ++i)
    {
        for (int r = 8; r >= 2; --r)
        {
            for (int c = 1; c <= 8; ++c)
            {
                board[r][c][i] = board[r-1][c][i - 1];
            }
        }

        for (int c = 1; c <= 8; ++c)
        {
            board[1][c][i] = true;
        }
    }
}

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > 8 || c > 8)
    {
        return true;
    }
    return false;
}

bool bfs()
{
    int goal_r = 1;
    int goal_c = 8;

    int r, c, t;
    int nr, nc;
    queue<tuple<int,int,int>> q;
    q.push({ 8,1,0 });
    is_visited[8][1][0] = true;
    bool can_arrive = false;

    while (!q.empty())
    {
        tie(r, c, t) = q.front();
        q.pop();

        if ((r == goal_r && c == goal_c) || r == 1)
        {
            can_arrive = true;
            break;
        }

        for (int i = 0; i < 9; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];
            if (OutOfBound(nr, nc) || is_visited[nr][nc][t + 1] || !board[nr][nc][t+1] || !board[nr][nc][t])
                continue;

            is_visited[nr][nc][t + 1] = true;
            q.push({ nr,nc,t + 1 });
        }
    }

    return can_arrive;
}

void print_board()
{
    for (int i = 0; i <= 8; ++i)
    {
        cout << i << "th board\n";
        for (int r = 1; r <= 8; ++r)
        {
            for (int c = 1; c <= 8; ++c)
            {
                cout << board[r][c][i];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

void print_visited_board()
{
    for (int i = 0; i <= 8; ++i)
    {
        cout << i << "th board\n";
        for (int r = 1; r <= 8; ++r)
        {
            for (int c = 1; c <= 8; ++c)
            {
                cout << is_visited[r][c][i];
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    //print_board();

    if (bfs())
        cout << 1;
    else
        cout << 0;

    //print_visited_board();
    return 0;
}