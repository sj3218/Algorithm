#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int board[1001][1001];
int H, W, Sr, Sc, Fr, Fc;

int is_visited[1001][1001];
bool can_visit[1001][1001];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0, 0 };

bool InRange(int r, int c)
{
    if (r <= 0 || r + H-1 > N || c <= 0 || c + W-1 > M)
    {
        return false;
    }

    return true;
}

void bfs()
{
    queue<pair<int, int>> q;

    q.push({ Sr,Sc });
    is_visited[Sr][Sc] = 1;

    int r, c;
    while (!q.empty())
    {
        r = q.front().first;
        c = q.front().second;
        q.pop();

        if (r == Fr && c == Fc)
        {
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (!InRange(nr, nc))
            {
                continue;
            }

            if (is_visited[nr][nc] != 0)
            {
                continue;
            }

            if (can_visit[nr][nc] == false)
                continue;

            is_visited[nr][nc] = is_visited[r][c] + 1;
            q.push({ nr,nc });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    fill_n(is_visited[0], 1001 * 1001, 0);
    fill_n(can_visit[0], 1001 * 1001, true);

    vector<pair<int, int>> wall_pos;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> board[i][j];

            if (board[i][j] == 1)
            {
                wall_pos.push_back({ i,j });
            }
        }
    }

    cin >> H >> W >> Sr >> Sc >> Fr >> Fc;

    int x, y;
    int size = wall_pos.size();

    for (int i = 0; i < size; ++i)
    {
        x = wall_pos[i].first;
        y = wall_pos[i].second;

        for (int r = x - H + 1; r <= x; ++r)
        {
            for (int c = y - W + 1; c <= y; ++c)
            {
                if (!InRange(r, c))
                {
                    continue;
                }
                can_visit[r][c] = false;
            }

        }
    }

    bfs();

    cout << is_visited[Fr][Fc] -1;
    return 0;
}