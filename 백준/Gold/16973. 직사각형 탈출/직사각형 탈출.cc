#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int arr[1001][1001];
int Sr, Sc;
int Fr, Fc;
int H, W;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int is_visited[1001][1001];
bool can_visit[1001][1001];
vector<pair<int, int>> wall_pos;

bool InRange(int x, int y)
{
    if (x <= 0 || y <= 0 || x + H - 1 > N || y + W - 1 > M)
    {
        return false;
    }

    //for (int i = x; i < x + H; ++i)
    //{
    //    for (int j = y; j < y + W; ++j)
    //    {
    //        if (arr[i][j] == 1)
    //        {
    //            return false;
    //        }
    //    }
    //}

    return true;
}

void Input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(is_visited[0], 1001 * 1001, -1);
    fill_n(can_visit[0], 1001 * 1001, true);

    cin >> N >> M;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 1)
            {
                wall_pos.push_back({ i, j });
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
                    continue;

                can_visit[r][c] = false;
            }
        }
    }
}

void BFS()
{
    queue<pair<int, int>> q;
    q.push({ Sr, Sc });
    is_visited[Sr][Sc] = 0;

    int x, y;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!InRange(nx, ny) || is_visited[nx][ny] != -1 || can_visit[nx][ny] == false)
                continue;

            q.push({ nx, ny });
            is_visited[nx][ny] = is_visited[x][y] + 1;
        }
    }
}

int main()
{
    Input();
    BFS();

    cout << is_visited[Fr][Fc];

    return 0;
}
