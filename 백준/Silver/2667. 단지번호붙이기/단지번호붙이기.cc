#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int N;
string line;
bool town[26][26];
int is_visited[26][26];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > N)
        return false;
    return true;
}

int bfs(int x, int y, int num)
{
    queue<pair<int, int>> q;
    q.push({ x, y });
    is_visited[x][y] = num;

    int cx, cy;
    int nx, ny;
    int cnt = 1;

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
            if (is_visited[nx][ny] != 0)
                continue;

            if (town[nx][ny] == false)
                continue;

            is_visited[nx][ny] = num;
            q.push({ nx,ny });
            ++cnt;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> line;
        for (int j = 1; j <= N; ++j)
        {
            if (line[j - 1] == '0')
            {
                town[i][j] = false;
            }
            else
            {
                town[i][j] = true;
            }
        }
    }

    vector<int> house;
    int cnt_house;
    int town_idx = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            if (is_visited[i][j] != 0)
            {
                continue;
            }
            if (!town[i][j])
                continue;

            ++town_idx;
            cnt_house = bfs(i, j, town_idx);
            house.push_back(cnt_house);
        }
    }

    cout << town_idx << "\n";
    sort(house.begin(), house.end());
    for (int i = 0; i < town_idx; ++i)
    {
        cout << house[i] << " \n";
    }

    return 0;
}
