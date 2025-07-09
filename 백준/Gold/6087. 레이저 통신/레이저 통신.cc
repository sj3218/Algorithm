#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

#define INF 0X7FFFFFFF

int W, H;
bool board[101][101]; // true: empty, false: wall
vector<pair<int, int>> connection_pos;
int is_visited[101][101][4];

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

void Input()
{
    cin >> W >> H;

    string s;
    for (int i = 1; i <= H; ++i)
    {
        cin >> s;
        for (int j = 1; j <= W; ++j)
        {
            if (s[j - 1] == '.')
            {
                board[i][j] = true;
            }
            else if (s[j - 1] == 'C')
            {
                // connection pos
                connection_pos.push_back({ i,j });
                board[i][j] = true;
            }
        }
    }
}

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > H || c > W)
        return true;
    return false;
}

int bfs()
{
    fill_n(&is_visited[0][0][0], 101 * 101 * 4, -1);

    pair<int, int> start = connection_pos[0];
    pair<int, int> end = connection_pos[1];
    queue<tuple<int,int,int>> q; //r, c, way
    
    int cr, cc, cw, nr, nc;
    int curr_mirror_cnt;
    cr = start.first;
    cc = start.second;

    int answer = INF;

    for (int i = 0; i < 4; ++i)
    {
        nr = cr + dr[i];
        nc = cc + dc[i];
        is_visited[start.first][start.second][i] = 0;

        if (OutOfBound(nr, nc) || !board[nr][nc])
            continue;

        q.push({ nr,nc,i });
        is_visited[nr][nc][i] = 0;
    }

    while (!q.empty())
    {
        cr = get<0>(q.front());
        cc = get<1>(q.front());
        cw = get<2>(q.front());
        q.pop();
        curr_mirror_cnt = is_visited[cr][cc][cw];

        if (cr == end.first && cc == end.second)
        {
            answer = min(answer, curr_mirror_cnt);
            continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];

            if (OutOfBound(nr, nc) || board[nr][nc] == false)
                continue;

            if (is_visited[nr][nc][i] <= curr_mirror_cnt && is_visited[nr][nc][i] != -1)
                continue;

            if (cw == i)
            {
                is_visited[nr][nc][i] = curr_mirror_cnt;
            }
            else
            {
                is_visited[nr][nc][i] = curr_mirror_cnt + 1;
            }

            q.push({ nr,nc,i });
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    Input();
    cout << bfs();

    return 0;
}