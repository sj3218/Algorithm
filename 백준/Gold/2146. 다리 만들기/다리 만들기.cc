#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#define INF 0x7fffffff

using namespace std;
int N;
int map[101][101];
bool is_visited[101][101];
int is_visited_map[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0,0 };

queue<tuple<int, int, int>> q_near_land;

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}

void IndexingMap(int X, int Y, int idx)
{
    queue<pair<int, int>> q;
    q.push({ X, Y });
    is_visited[X][Y] = true;
    map[X][Y] = idx;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny] || map[nx][ny] == 0)
                continue;

            q.push({ nx,ny });
            is_visited[nx][ny] = true;
            map[nx][ny] = idx;
        }
    }
}

int bfs()
{
    int answer = INF;
    while (!q_near_land.empty())
    {
        int X = get<0>(q_near_land.front());
        int Y = get<1>(q_near_land.front());
        int idx = get<2>(q_near_land.front());
        q_near_land.pop();

        fill_n(is_visited_map[0], 101 * 101, 0);
        queue<pair<int, int>> q;
        q.push({ X, Y });
        is_visited_map[X][Y] = 1;

        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            int cnt = is_visited_map[x][y];
            q.pop();
            
            if (map[x][y] != 0 && map[x][y] != idx)
            {
                answer = min(answer, is_visited_map[x][y]);
                break;

            }

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (!IsValid(nx, ny) || is_visited_map[nx][ny] != 0)
                    continue;

                if (map[nx][ny] == idx)
                    continue;

                is_visited_map[nx][ny] = cnt + 1;
                q.push({ nx, ny });
            }
        }

    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
        }
    }

    int idx = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (map[i][j] == 1 && is_visited[i][j] == false)
            {
                ++idx;
                IndexingMap(i, j, idx);
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (map[i][j] == 0)
            {
                for (int k = 0; k < 4; ++k)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (IsValid(nx, ny) && map[nx][ny] > 0)
                    {
                        q_near_land.push({ i,j, map[nx][ny] });
                        break;
                    }
                }
            }
        }
    }

    cout << bfs() -1;
    return 0;
}