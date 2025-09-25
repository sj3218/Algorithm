#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

struct track
{
    int x;
    int y;
    int dist;
};

int N, M;
vector<pair<int, int>> points;
track is_visited[101][101];
bool has_line[101][101];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1, 0,0 };

void Input()
{
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < 4; ++i)
    {
        cin >> a >> b;
        points.push_back({ a,b });
    }
}

bool OutOfBound(int x, int y)
{
    if (x <0 || y < 0 || x>N || y > M)
        return true;
    return false;
}

void MakeLine(pair<int,int> goal)
{
    int cx = goal.first;
    int cy = goal.second;
    int temp;

    fill_n(&has_line[0][0], 101 * 101, false);

    while (cx != -1 && cy != -1)
    {
        has_line[cx][cy] = true;
        temp = is_visited[cx][cy].x;
        cy = is_visited[cx][cy].y;
        cx = temp;
    }
}

bool bfs(pair<int, int> start, pair<int, int> goal, bool first_check)
{
    queue<pair<int,int>> q;
    int cx, cy;
    int nx, ny;
    int length;
    cx = start.first;
    cy = start.second;
    q.push({ cx,cy });
    is_visited[cx][cy] = { -1,-1, 0 };

    while (!q.empty())
    {
        tie(cx, cy) = q.front(); q.pop();
        length = is_visited[cx][cy].dist;
        
        if (cx == goal.first && cy == goal.second)
        {
            if (first_check)
                MakeLine(goal);

            return true;
        }
        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (OutOfBound(nx, ny) || is_visited[nx][ny].dist != -1)
                continue;

            if (!first_check && has_line[nx][ny])
                continue;

            q.push({ nx,ny });
            is_visited[nx][ny] = { cx,cy,length + 1 };
        }
    }
    return false;
}

void Init(bool run_bfs_a)
{
    fill_n(&is_visited[0][0], 101 * 101, track{ -1,-1,-1 });
    if (run_bfs_a)
    {
        is_visited[points[2].first][points[2].second] = { -1,-1,0 };
        is_visited[points[3].first][points[3].second] = { -1,-1,0 };
    }
    else
    {
        is_visited[points[0].first][points[0].second] = { -1,-1,0 };
        is_visited[points[1].first][points[1].second] = { -1,-1,0 };
    }
}

void Solution()
{
    int total_length = 0;
    int length_1 = 0;
    int length_2 = 0;
    bool succeed_ab = true;

    //a -> b
    Init(true);
    if (bfs(points[0], points[1], true))
    {
        length_1 = is_visited[points[1].first][points[1].second].dist;
        Init(false);
        if (bfs(points[2], points[3], false))
        {
            length_2 = is_visited[points[3].first][points[3].second].dist;
            total_length = length_1 + length_2;
        }
        else
            succeed_ab = false;
    }
    
    //b -> a
    Init(false);
    fill_n(&has_line[0][0], 101 * 101, false);
    if (bfs(points[2], points[3], true))
    {
        length_1 = is_visited[points[3].first][points[3].second].dist;
        Init(true);
        if (bfs(points[0], points[1], false))
        {
            length_2 = is_visited[points[1].first][points[1].second].dist;
            if (succeed_ab)
            {
                total_length = min(total_length, length_1 + length_2);
            }
            else
                total_length = length_1 + length_2;
        }
    }

    if (total_length == 0)
        cout << "IMPOSSIBLE";
    else
        cout << total_length;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    Input();
    Solution();

    return 0;
}