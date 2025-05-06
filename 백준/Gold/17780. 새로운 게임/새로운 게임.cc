#include <iostream>
#include <algorithm>
#include <vector>

#define GAME_END        1000
#define WHITE_BOARD     0
#define RED_BOARD       1
#define BLUE_BOARD      2
#define OVER_KNIGHTS    4

using namespace std;

int N, K;
int board[15][15];
vector<int> board_with_knight[15][15];

struct Knight
{
    bool can_move;
    int x, y, w;
}knights[11];

int dx[5] = {0,0,0,-1,1};
int dy[5] = {0,1,-1,0,0};

void Input()
{
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[i][j];
        }
    }

    int x, y, w;
    for (int i = 0; i < K; ++i)
    {
        cin >> x >> y >> w;
        knights[i] = { true, x, y, w };
        board_with_knight[x][y].push_back(i);
    }
}

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > N)
    {
        return false;
    }
    return true;
}

int ReverseKnight(int x, int y)
{
    reverse(board_with_knight[x][y].begin(), board_with_knight[x][y].end());
    
    int idx = board_with_knight[x][y][0];
    int last_idx = board_with_knight[x][y][board_with_knight[x][y].size() - 1];

    knights[last_idx].can_move = false;
    knights[idx].can_move = true;

    return idx;
}

void ChangeDirection(int idx)
{
    int way = knights[idx].w;
    if (way == 1)
        way = 2;
    else if (way == 2)
        way = 1;
    else if (way == 3)
        way = 4;
    else
        way = 3;
    
    knights[idx].w = way;
}

void MoveKnight(int idx, int cx, int cy, int& nx, int& ny, int board_color)
{
    if (board_color == WHITE_BOARD)
    {
        if (board_with_knight[nx][ny].size() > 0)
            knights[idx].can_move = false;

        for (int next : board_with_knight[cx][cy])
        {
            board_with_knight[nx][ny].push_back(next);
            knights[next].x = nx;
            knights[next].y = ny;
        }
        board_with_knight[cx][cy].clear();
    }
    else if (board_color == RED_BOARD)
    {
        idx = ReverseKnight(cx, cy);

        if (board_with_knight[nx][ny].size() > 0)
        {
            knights[idx].can_move = false;
        }

        for (int next : board_with_knight[cx][cy])
        {
            board_with_knight[nx][ny].push_back(next);
            knights[next].x = nx;
            knights[next].y = ny;
        }

        board_with_knight[cx][cy].clear();
    }
    else
    {
        ChangeDirection(idx);
        int way = knights[idx].w;
        nx = cx + dx[way];
        ny = cy + dy[way];

        if (IsValid(nx, ny) && board[nx][ny] != BLUE_BOARD)
            MoveKnight(idx, cx, cy, nx, ny, board[nx][ny]);
    }
}

void PrintBoard(int idx)
{
    cout << idx << "\n";

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << board_with_knight[i][j].size() << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}

void Solution()
{
    Input();

    int answer = 0;
    bool has_over_knight = false;

    while (true)
    {
        if (has_over_knight == true)
            break;
        if (answer > GAME_END)
        {
            cout << -1;
            return;
        }

        for (int i = 0; i < K; ++i)
        {
            if (!knights[i].can_move)
                continue;

            int cx = knights[i].x;
            int cy = knights[i].y;
            int cw = knights[i].w;

            int nx = cx + dx[cw];
            int ny = cy + dy[cw];

            if (!IsValid(nx, ny))
            {
                MoveKnight(i, cx, cy, nx, ny, BLUE_BOARD);
            }
            else
                MoveKnight(i, cx, cy, nx, ny, board[nx][ny]);

            if (board_with_knight[nx][ny].size() >= OVER_KNIGHTS)
            {
                has_over_knight = true;
                break;
            }
        }
        ++answer;

        //PrintBoard(answer);
    }

    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Solution();
    return 0;
}