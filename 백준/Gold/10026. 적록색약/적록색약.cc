#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int N;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0,0 };
char painting[101][101];
int is_visited[101][101];
int is_visited_cannot_see[101][101];
int cnt_can_see = 0;
int cnt_cannot_see = 0;

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}

void BFS(int X, int Y, bool can_see)
{
    if (can_see == true)
    {
        if (is_visited[X][Y] != -1)
            return;
    }
    else
        if (is_visited_cannot_see[X][Y] != -1)
            return;

    
    queue<pair<int, int>> q;
    q.push({ X, Y });
    char color = painting[X][Y];

    if (can_see)
        is_visited[X][Y] = ++cnt_can_see;
    else
        is_visited_cannot_see[X][Y] = ++cnt_cannot_see;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (can_see)
            {
                if (!IsValid(nx, ny) || is_visited[nx][ny] != -1 || painting[nx][ny] != color)
                    continue;

                q.push({ nx, ny });
                is_visited[nx][ny] = cnt_can_see;
            }
            else
            {
                if (!IsValid(nx, ny) || is_visited_cannot_see[nx][ny] != -1)
                    continue;

                if (color == 'B' && painting[nx][ny] != 'B')
                    continue;

                if (color != 'B' && painting[nx][ny] == 'B')
                    continue;

                q.push({ nx, ny });
                is_visited_cannot_see[nx][ny] = cnt_cannot_see;
            }
            
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    fill_n(is_visited[0], 101 * 101, -1);
    fill_n(is_visited_cannot_see[0], 101 * 101, -1);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; ++j)
        {
            painting[i][j] = s[j];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            BFS(i, j, true);
            BFS(i, j, false);
        }
    }

    cout << cnt_can_see << " " << cnt_cannot_see;

    return 0;
}