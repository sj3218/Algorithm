#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define BOARD_SIZE 10
#define EMPTY   0
#define WALL    1
#define VIRUS   2
#define WALL_SIZE   3

using namespace std;

int N, M;
int board[BOARD_SIZE][BOARD_SIZE];
vector<pair<int, int>> virus_pos;
int answer = 0;
int init_empty_cnt;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= M)
        return false;
    return true;
}

int SpreadVirus()
{
    bool is_visited[BOARD_SIZE][BOARD_SIZE];
    fill_n(&is_visited[0][0], BOARD_SIZE * BOARD_SIZE, false);

    queue<pair<int, int>> q;
    for (pair<int, int> next : virus_pos)
    {
        q.push(next);
        is_visited[next.first][next.second] = true;
    }

    int cx, cy;
    int nx, ny;
    int spread_cnt = 0;
    while (!q.empty())
    {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];
            if (!IsValid(nx, ny))
                continue;
            if (is_visited[nx][ny])
                continue;
            if (board[nx][ny] != EMPTY)
                continue;

            is_visited[nx][ny] = true;
            q.push({ nx,ny });
            ++spread_cnt;
        }
    }

    return init_empty_cnt - spread_cnt;
}

void PlaceWalls(int count)
{
    if (count == WALL_SIZE)
    {
        int cnt = SpreadVirus();
        answer = max(answer, cnt);
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (board[i][j] == WALL || board[i][j] == VIRUS)
                continue;

            board[i][j] = WALL;
            PlaceWalls(count + 1);
            board[i][j] = EMPTY;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == VIRUS)
                virus_pos.push_back({ i,j });
            else if (board[i][j] == EMPTY)
                ++init_empty_cnt;
        }
    }

    init_empty_cnt -= 3;// 세울 벽 3개 제외
    PlaceWalls(0);
    cout << answer;

    return 0;
}