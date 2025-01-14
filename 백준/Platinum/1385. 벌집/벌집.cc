#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#define SIZE 1160

using namespace std;

int board[SIZE][SIZE];
int a, b;
pair<int, int> is_visited[SIZE][SIZE];
int sx, sy, ex, ey;

int dx[6] = { 0,1,1,0,-1,-1 };
int dy[6] = { 1,1,0,-1,-1,0 };

void MakeBoard()
{
    int x = SIZE / 2;
    int y = SIZE / 2;

    int layer = 1;
    int num = 1;
    
    board[x][y] = num; 
    if (num == a)
    {
        sx = x;
        sy = y;
    }
    if (num == b)
    {
        ex = x;
        ey = y;
    }
    
    while (num <= 1000000)
    {
        --x;
        board[x][y] = ++num;
        if (num == a)
        {
            sx = x;
            sy = y;
        }
        if (num == b)
        {
            ex = x;
            ey = y;
        }


        for (int l = 0; l < layer - 1; ++l)
        {
            x += dx[0];
            y += dy[0];
            board[x][y] = ++num;

            if (num == a)
            {
                sx = x;
                sy = y;
            }
            if (num == b)
            {
                ex = x;
                ey = y;
            }
        }

        for (int i = 1; i < 6; ++i)
        {
            for (int j = 0; j < layer; ++j)
            {
                x += dx[i];
                y += dy[i];
                board[x][y] = ++num;

                if (num == a)
                {
                    sx = x;
                    sy = y;
                }
                if (num == b)
                {
                    ex = x;
                    ey = y;
                }
            }
        }

        ++layer;
    }
}

bool InRange(int x, int y)
{
    if (x < 0 || y < 0 || x >= SIZE || y >= SIZE || board[x][y] == 0)
    {
        return false;
    }
    return true;
}

pair<int,int> bfs()
{
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    is_visited[sx][sy] = { sx,sy };

    int x, y;
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        if (x == ex && y == ey)
        {
            return { x, y };
        }

        for (int i = 0; i < 6; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && is_visited[nx][ny] == make_pair(0, 0))
            {
                is_visited[nx][ny] = { x, y };
                q.push({ nx, ny });
            }
        }
    }

    return { 0,0 };
}

void PrintPath(pair<int, int> exit) {
    vector<int> ans;
    for (int x = exit.first, y = exit.second; !(x == sx && y == sy); ) {
        ans.push_back(board[x][y]);
        tie(x, y) = is_visited[x][y];
    }

    ans.push_back(board[sx][sy]);
    reverse(ans.begin(), ans.end());

    for (int room : ans) {
        cout << room << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> a >> b;

    MakeBoard();

    PrintPath(bfs());

    return 0;
}