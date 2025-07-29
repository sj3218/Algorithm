#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

#define INF 0X7FFFFFFF
using namespace std;

int N;
int board[101][101];
bool is_visited[101][101];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
int answer = INF;

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > N || c > N)
        return true;
    return false;
}

bool bfs(int _min, int _max)
{
    fill_n(&is_visited[0][0], 101 * 101, false);

    queue<pair<int, int>> q;
    q.push({ 1,1 });
    is_visited[1][1] = true;
    if (_min > board[1][1] || board[1][1] > _max)
        return false;

    int cr, cc;
    int nr, nc;
    int min_value = INF;
    int max_value = -1;
    
    while (!q.empty())
    {
        tie(cr, cc) = q.front();
        q.pop();

        min_value = min(min_value, board[cr][cc]);
        max_value = max(max_value, board[cr][cc]);

        if (cr == N && cc == N)
        {
            answer = min(answer, max_value - min_value);
            return true;
        }

        for (int i = 0; i < 4; ++i)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];
            if (OutOfBound(nr, nc))
                continue;
            if (is_visited[nr][nc])
                continue;
            if (board[nr][nc] < _min || board[nr][nc] >_max)
                continue;

            is_visited[nr][nc] = true;
            q.push({ nr,nc });
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    int start = 0;
    int end = 200;
    int mid;
    int min_num = INF;
    int max_num = -1;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[i][j];
            min_num = min(min_num, board[i][j]);
            max_num = max(max_num, board[i][j]);
        }
    }

    end = max_num - min_num;

    while (start <= end)
    {
        bool can_reach = false;

        mid = (start + end) / 2;

        for (int i = min_num; i <= max_num; ++i)
        {
            if (bfs(i, i + mid))
            {
                can_reach = true;
                break;
            }
        }

        if (can_reach)
            end = mid - 1;
        else
            start = mid + 1;
    }

    cout << answer;
    return 0;
}