#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;

int n, m;
bool board[501][501];
bool is_visited[501][501];

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

void Input()
{
    cin >> n >> m;
    int value;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> value;
            if (value == 0)
                board[i][j] = false;
            else
                board[i][j] = true;
        }
    }
}

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > n || c > m)
        return true;
    return false;
}

int Count_Area(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({ r,c });
    is_visited[r][c] = true;

    int nr, nc;
    int cr, cc;
    int area = 0;

    while (!q.empty())
    {
        tie(cr, cc) = q.front();
        q.pop();
        ++area;

        for (int i = 0; i < 4; ++i)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];
            if (OutOfBound(nr, nc))
                continue;

            if (is_visited[nr][nc] || !board[nr][nc])
                continue;

            q.push({ nr,nc });
            is_visited[nr][nc] = true;

        }
    }

    return area;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    int max_area = 0;
    int count_area = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (board[i][j] && is_visited[i][j] == false)
            {
                ++count_area;
                max_area = max(max_area, Count_Area(i, j));
            }
        }
    }

    cout << count_area << "\n" << max_area;
    return 0;
}