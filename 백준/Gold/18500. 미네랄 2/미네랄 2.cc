#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0x7FFFFFFF

using namespace std;

int R, C;
int N;
bool board[101][101];
bool is_visited[101][101];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void DropCluster(vector<pair<int,int>> cluster)
{
    int down_cnt = INF;

    for (pair<int, int> next : cluster)
    {
        int cur_cnt = 0;

        int x = next.first;
        int y = next.second;

        for (int i = x + 1; i <= R; ++i)
        {
            if (board[i][y])
            {
                if (is_visited[i][y] == false)
                    cur_cnt = INF;

                break;
            }
            ++cur_cnt;
        }

        down_cnt = min(down_cnt, cur_cnt);
    }

    for (pair<int, int> next : cluster)
    {
        int x = next.first;
        int y = next.second;
        board[x][y] = false;
    }
    for (pair<int, int>next : cluster)
    {
        int x = next.first + down_cnt;
        int y = next.second;
        board[x][y] = true;
    }
}

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > R || y > C)
        return false;
    return true;
}

void bfs(int x, int y)
{
    queue < pair<int, int>>q;
    q.push({ x,y });
    is_visited[x][y] = true;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny] || !board[nx][ny])
                continue;

            is_visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

vector<pair<int, int>> FindCluster(int x, int y)
{
    vector<pair<int, int>> cluster;
    fill_n(&is_visited[0][0], 101 * 101, false);

    for (int i = 1; i <= C; ++i)
    {
        if (board[R][i] && !is_visited[R][i])
        {
            bfs(R, i);
        }
    }

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (board[i][j] && is_visited[i][j] == false)
            {
                cluster.push_back({ i,j });
            }
        }
    }
    return cluster;
}

void ThrowStick(bool left_way, int height)
{
    int width = INF;

    if (left_way)
    {
        for (int i = 1; i <= C; ++i)
        {
            if (board[height][i])
            {
                width = i;
                board[height][i] = false;
                break;
            }
        }
    }
    else
    {
        for (int i = C; i > 0; --i)
        {
            if (board[height][i])
            {
                width = i;
                board[height][i] = false;
                break;
            }
        }
    }

    if (width == INF)
        return;

    vector<pair<int,int>> cluster = FindCluster(height, width);
    if (cluster.size() != 0)
    {
        DropCluster(cluster);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> R >> C;
    char c;

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            cin >> c;
            if (c == 'x')
            {
                board[i][j] = true;
            }
        }
    }

    cin >> N;
    bool left_way = true;
    int height;

    for (int i = 0; i < N; ++i)
    {
        cin >> height;
        ThrowStick(left_way, R - height + 1);
        left_way = !left_way;
    }

    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (board[i][j])
            {
                cout << "x";
            }
            else
                cout << ".";
        }
        cout << "\n";
    }
    return 0;
}