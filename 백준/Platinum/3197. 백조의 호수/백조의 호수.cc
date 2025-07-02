#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int Row, Col;
vector<pair<int, int>> swan_pos;
bool has_ice[1501][1501];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
bool is_visited[1501][1501];
bool water_visited[1501][1501];
queue<pair<int, int>> next_swan_queue;
queue<pair<int, int >> water_queue;

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > Row || c > Col)
        return true;
    return false;
}

void Input()
{
    string s;
    int nr, nc;
    cin >> Row >> Col;
    for (int i = 1; i <= Row; ++i)
    {
        cin >> s;
        for (int j = 1; j <= Col; ++j)
        {
            if (s[j - 1] == 'L')
            {
                swan_pos.push_back({ i,j });
            }
            else if (s[j - 1] == 'X')
            {
                has_ice[i][j] = true;
            }
        }
    }

    //water_queue에 빙하 옆에 있는 물 위치들 큐에 넣기
    for (int i = 1; i <= Row; ++i)
    {
        for (int j = 1; j <= Col; ++j)
        {
            if (has_ice[i][j] != false)
                continue;

            for (int k = 0; k < 4; ++k)
            {
                nr = i + dr[k];
                nc = j + dc[k];
                if (OutOfBound(nr, nc) || is_visited[nr][nc])
                    continue;

                if (has_ice[nr][nc] != true)
                    continue;

                is_visited[nr][nc] = true;
                water_queue.push({ i, j });
                water_visited[i][j] = true;
                break;
            }
        }
    }

    //next_swan_queue에 한마리 백조 위치 넣어주기
    fill_n(&is_visited[0][0], 1501 * 1501, false);
    next_swan_queue.push(swan_pos[0]);
    is_visited[swan_pos[0].first][swan_pos[0].second] = true;
}

void MeltIce()
{
    int r, c;
    int nr, nc;
    int cnt = water_queue.size();

    while (cnt--)
    {
        tie(r, c) = water_queue.front();
        water_queue.pop();

        for (int i = 0; i < 4; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];
            if (OutOfBound(nr, nc) || !has_ice[nr][nc])
                continue;

            if (water_visited[nr][nc])
                continue;

            has_ice[nr][nc] = false;
            water_visited[nr][nc] = true;
            water_queue.push({ nr,nc });
        }
    }
}

bool CanMeet(int goal_r, int goal_c)
{
    queue<pair<int, int>>q;
    next_swan_queue.swap(q);

    int nr, nc;
    int cr, cc;
    while (!q.empty())
    {
        cr = q.front().first;
        cc = q.front().second;
        q.pop();

        if (goal_r == cr && goal_c == cc)
            return true;

        for (int i = 0; i < 4; ++i)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];
            if (OutOfBound(nr, nc))
                continue;

            if (is_visited[nr][nc] == true)
                continue;

            if (has_ice[nr][nc])
                next_swan_queue.push({ nr,nc });
            else
                q.push({ nr,nc });

            is_visited[nr][nc] = true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    int days = 0;
    int goal_r = swan_pos[1].first;
    int goal_c = swan_pos[1].second;

    while (!CanMeet(goal_r, goal_c))
    {
        ++days;
        MeltIce();
    }

    cout << days;
    return 0;
}