#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int N, M, K;

bool board[1001][1001];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int is_visited[1001][1001][11];

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > M)
        return false;
    return true;
}

int bfs()
{
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, {1,1} });
    is_visited[1][1][0] = 1;

    int cx, cy;
    int nx, ny;
    int ck;
    int curr_dist;

    while (!q.empty())
    {
        ck = q.front().first;
        cx = q.front().second.first;
        cy = q.front().second.second;
        curr_dist = is_visited[cx][cy][ck];
        q.pop();

        if (cx == N && cy == M)
            return curr_dist;

        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (!IsValid(nx, ny))
                continue;

            if (is_visited[nx][ny][ck] != -1)
                continue;

            if (board[nx][ny] == false)
            {
                if (ck == K)
                    continue;
                if (is_visited[nx][ny][ck + 1] != -1)
                    continue;

                is_visited[nx][ny][ck + 1] = curr_dist + 1;
                q.push({ ck + 1, {nx,ny} });
            }
            else
            {
                is_visited[nx][ny][ck] = curr_dist + 1;
                q.push({ ck, {nx,ny} });
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(&is_visited[0][0][0], 1001 * 1001 * 11, -1);
    cin >> N >> M >> K;
    string line;
    for (int i = 1; i <= N; ++i)
    {
        cin >> line;
        for (int j = 1; j <= M; ++j)
        {
            if (line[j - 1] == '0')
                board[i][j] = true;
            else
                board[i][j] = false;
        }
    }
    cout << bfs();

    return 0;
}
