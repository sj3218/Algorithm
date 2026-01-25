#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;

const int UNRIPE = -1;
const int ALL_RPIE = 0;

int N, M;
int board[1001][1001];
int is_visitied[1001][1001];

int cnt_not_ripe = 0;
queue<pair<int, int>> pos_ripe;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

bool OutofBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > N || c > M)
    {
        return true;
    }
    return false;
}

void Input()
{
    fill_n(&is_visitied[0][0], 1001 * 1001, -1);

    cin >> M >> N;

    for (int r = 1; r <= N; ++r)
    {
        for (int c = 1; c <= M; ++c)
        {
            cin >> board[r][c];
            if (board[r][c] == 0)
                ++cnt_not_ripe;
            else if (board[r][c] == 1)
            {
                pos_ripe.push({ r,c });
                is_visitied[r][c] = 0;
            }
        }
    }
}

int GetRipeningDays(int& cnt_ripe)
{
    int cr, cc, nr, nc;
    int max_day = -1;
    int curr_day = 0;

    while (!pos_ripe.empty())
    {
        tie(cr, cc) = pos_ripe.front();
        pos_ripe.pop();
        curr_day = is_visitied[cr][cc];
        
        max_day = max(max_day, curr_day);
        if (board[cr][cc] == 0)
            ++cnt_ripe;

        for (int i = 0; i < 4; ++i)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];

            if (OutofBound(nr, nc) || (is_visitied[nr][nc] != -1) || (board[nr][nc] != 0))
            {
                continue;
            }

            is_visitied[nr][nc] = curr_day + 1;
            pos_ripe.push({ nr,nc });
        }
    }

    return max_day;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    if (cnt_not_ripe == 0)
    {
        //all tomatoes are ripen at the first
        cout << ALL_RPIE;
        return 0;
    }
    
    int cnt_ripe = 0;
    int max_day = GetRipeningDays(cnt_ripe);
    if (cnt_ripe != cnt_not_ripe)
    {
        //all tomatoes are not ripen
        cout << UNRIPE;
    }
    else
    {
        cout << max_day;
    }

    return 0;
}