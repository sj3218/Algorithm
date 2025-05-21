#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define INF 0X7FFFFFFF

using namespace std;

int N, M;
int cnt_player;
int move_distance[10];
int board[1001][1001];

vector<pair<int, int>> castles_pos[10];
vector<int> total_castles_pos(10);
int cnt_castles = 0;
int total_castle;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > M)
        return false;
    return true;
}

void bfs(int idx)
{
    queue<pair<int, pair<int, int>>> q;
    int dist = move_distance[idx];
    
    for (pair<int, int> next : castles_pos[idx])
    {
        q.push({ 0, next });
    }

    castles_pos[idx].clear();

    int curr_dist, next_dist, cx, cy, nx, ny;
    while (!q.empty())
    {
        curr_dist = q.front().first;
        cx = q.front().second.first;
        cy = q.front().second.second;
        q.pop();
        
        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];
            next_dist = curr_dist + 1;

            if (!IsValid(nx, ny) || board[nx][ny] != 0)
                continue;

            ++cnt_castles;
            board[nx][ny] = idx;
            total_castles_pos[idx]++;
            castles_pos[idx].push_back({ nx,ny });
            if (next_dist < dist)
            {
                q.push({ next_dist, {nx,ny} });
            }
        }
    }
}

void Solution()
{
    while (true)
    {
        if (total_castle == cnt_castles)
        {
            break;
        }

        bool there_is_no_way = true;

        for (int i = 1; i <= cnt_player; ++i)
        {
            if (castles_pos[i].size() != 0)
            {
                there_is_no_way = false;
                break;
            }
        }

        if (there_is_no_way)
            break;

        for (int i = 1; i <= cnt_player; ++i)
        {
            bfs(i);
        }
    }

    for (int i = 1; i <= cnt_player; ++i)
    {
        cout << total_castles_pos[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    cin >> cnt_player;

    for (int i = 1; i <= cnt_player; ++i)
    {
        cin >> move_distance[i];
    }

    total_castle = N * M;

    string line;
    int player_idx;
    for (int i = 1; i <= N; ++i)
    {
        cin >> line;
        for (int j = 1; j <= M; ++j)
        {
            if (line[j - 1] == '.')
            {
                board[i][j] = 0;
            }
            else if (line[j - 1] == '#')
            {
                board[i][j] = -1;
                --total_castle;
            }
            else
            {
                player_idx = line[j - 1] - '0';
                board[i][j] = player_idx;
                ++cnt_castles;

                castles_pos[player_idx].push_back({ i,j });
                total_castles_pos[player_idx]++;
            }
        }
    }

    Solution();
    return 0;
}