#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, K, R;
bool board[101][101];
vector<pair<int, int>> cows;
bool road[101][101][4];
bool is_visited[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > N)
    {
        return false;
    }
    return true;
}

int bfs(int x, int y)
{
    int cnt = 0;

    queue<pair<int, int>> q;
    is_visited[x][y] = true;
    q.push({ x,y });

    int cx, cy, nx, ny;

    while (!q.empty())
    {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        if (board[cx][cy])
            ++cnt;

        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (!IsValid(nx, ny))
                continue;

            if (is_visited[nx][ny])
                continue;

            if (road[cx][cy][i])
                continue;

            is_visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int answer = 0;

    cin >> N >> K >> R;
    int r1, r2, c1, c2;
    for (int i = 0; i < R; ++i)
    {
        cin >> r1 >> c1 >> r2 >> c2;

        if (r1 == r2)
        {
            if (c1 == c2 - 1)
            {
                road[r1][c1][0] = true;
                road[r2][c2][1] = true;
            }
            else
            {
                road[r1][c1][1] = true;
                road[r2][c2][0] = true;
            }
        }
        else
        {
            if (r1 == r2 - 1)
            {
                road[r1][c1][2] = true;
                road[r2][c2][3] = true;
            }
            else
            {
                road[r1][c1][3] = true;
                road[r2][c2][2] = true;
            }
        }
    }

    for (int i = 0; i < K; ++i)
    {
        cin >> r1 >> c1;
        cows.push_back({ r1,c1 });
        board[r1][c1] = true;
    }

    for (pair<int, int> cow : cows)
    {
        fill_n(&is_visited[0][0], 101 * 101, false);
        int cnt_cow = bfs(cow.first, cow.second)-1; // 자기 자신 빼기
        answer += (K - cnt_cow-1);
    }

    cout << answer / 2;
    return 0;
}