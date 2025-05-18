#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int board_size, cnt_switch;
vector<pair<int, int>> board[101][101];
bool is_visited[101][101];
bool turn_on_light[101][101];
int answer = 1;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > board_size || y > board_size)
        return false;
    return true;
}

bool IsConnected(int x, int y)
{
    int nx, ny;
    for (int i = 0; i < 4; ++i)
    {
        nx = x + dx[i];
        ny = y + dy[i];
        if (!IsValid(nx, ny))
            continue;
        if (is_visited[nx][ny])
            return true;
    }
    return false;
}

void bfs()
{
    queue<pair<int, int>> pos_q;

    pos_q.push({ 1,1 });
    is_visited[1][1] = true;
    turn_on_light[1][1] = true;

    int cx, cy;
    int nx, ny;
    while (!pos_q.empty())
    {
        cx = pos_q.front().first;
        cy = pos_q.front().second;
        pos_q.pop();

        for (pair<int, int> light : board[cx][cy])
        {
            nx = light.first;
            ny = light.second;
            if (turn_on_light[nx][ny] || is_visited[nx][ny])
                continue;
            
            turn_on_light[nx][ny] = true;
            ++answer;
            if (IsConnected(nx, ny))
            {
                is_visited[nx][ny] = true;
                pos_q.push({ nx,ny });
            }
        }

        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny])
                continue;

            if (turn_on_light[nx][ny])
            {
                is_visited[nx][ny] = true;
                pos_q.push({ nx,ny });
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x1, x2, y1, y2;
    cin >> board_size >> cnt_switch;

    for (int i = 0; i < cnt_switch; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        board[x1][y1].push_back({ x2, y2 });
    }

    bfs();
    answer = 0;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            if (turn_on_light[i][j])
                ++answer;
        }
    }
    cout << answer;
    return 0;
}