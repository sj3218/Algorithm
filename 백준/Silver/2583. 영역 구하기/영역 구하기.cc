#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, K;
bool is_visited[101][101];
bool board[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= M || y >= N)
        return false;
    return true;
}

int bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    is_visited[x][y] = true;

    int cnt = 1;

    int cx, cy, nx, ny;
    while (!q.empty())
    {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny])
            {
                continue;
            }

            if (board[nx][ny])
            {
                continue;
            }

            is_visited[nx][ny] = true;
            q.push({ nx, ny });
            ++cnt;
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> M >> N >> K;

    int x1, y1, x2, y2;

    for (int i = 0; i < K; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        for (int y = y1; y < y2; ++y)
        {
            for (int x = x1; x<x2; ++x)
            {
                board[y][x] = true;
            }
        }
    }

    vector<int> answer;
    int area;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (!board[i][j] && !is_visited[i][j])
            {
                area = bfs(i, j);
                answer.push_back(area);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() <<"\n";
    for (int area : answer)
    {
        cout << area << " ";
    }
    return 0;
}