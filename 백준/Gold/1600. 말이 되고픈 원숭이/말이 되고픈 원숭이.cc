#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int K, W, H;
bool board[201][201];
int is_visited[201][201][31];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0,0 };
int h_dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int h_dy[8] = { -2,-1,1,2,2,1,-1,-2 };

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= H || y >= W)
        return false;
    return true;
}

int bfs()
{
    int answer = -1;

    queue<tuple<int, int, int>> q;
    q.push({ 0,0,K });
    is_visited[0][0][K] = 0;

    int x, y;
    int k;
    int nx, ny;
    int cnt_path;

    while (!q.empty())
    {
        x = get<0>(q.front());
        y = get<1>(q.front());
        k = get<2>(q.front());
        q.pop();

        if (x == H - 1 && y == W - 1)
        {
            answer = is_visited[x][y][k];
            return answer;
        }

        cnt_path = is_visited[x][y][k];

        //move monkey-way
        for (int i = 0; i < 4; ++i)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny][k] != -1)
                continue;

            if (board[nx][ny] == 1)
                continue;
            is_visited[nx][ny][k] = cnt_path + 1;
            q.push({ nx, ny, k });
        }

        //move horse-way
        for (int i = 0; i < 8; ++i)
        {
            nx = x + h_dx[i];
            ny = y + h_dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny][k-1] != -1 || k == 0)
                continue;

            if (board[nx][ny] == 1)
                continue;
            is_visited[nx][ny][k - 1] = cnt_path + 1;
            q.push({ nx, ny, k - 1 });
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(is_visited[0][0], 201 * 201 * 31, -1);

    cin >> K >> W >> H;

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << bfs();
    return 0;
}