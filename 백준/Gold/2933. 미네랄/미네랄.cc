#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int R, C;
bool cave[101][101]; //true: has_mineral
int cnt_throw;
vector<int> pos_throw;
vector<vector<pair<int, int>>> need_to_fall_minerals;
bool is_visited[101][101];
int dr[4] = { 0,0,-1,1 };
int dc[4] = { 1,-1,0,0 };

void Input()
{
    cin >> R >> C;
    string s;
    for (int i = 1; i <= R; ++i)
    {
        cin >> s;
        for (int j = 1; j <= C; ++j)
        {
            if (s[j - 1] == 'x')
                cave[i][j] = true;
        }
    }

    cin >> cnt_throw;
    int a;
    for (int i = 0; i < cnt_throw; ++i)
    {
        cin >> a;
        pos_throw.push_back(R- a + 1);
    }
}

void print_cave()
{
    for (int i = 1; i <= R; ++i)
    {
        for (int j = 1; j <= C; ++j)
        {
            if (cave[i][j])
                cout << 'x';
            else
                cout << '.';
        }
        cout << "\n";
    }
}

bool OutOfBounds(int r, int c)
{
    if (r <= 0 || c <= 0 || r > R || c > C)
        return true;
    return false;
}

void FindMinerals(int r, int c)
{
    fill_n(&is_visited[0][0], 101 * 101, false);
    need_to_fall_minerals.clear();
    is_visited[r][c] = true;

    int cr, cc, nr, nc;
    for (int way = 0; way < 4; ++way)
    {
        cr = r + dr[way];
        cc = c + dc[way];
        if (OutOfBounds(cr, cc) || is_visited[cr][cc] || cave[cr][cc] == false)
            continue;

        vector<pair<int, int>> temp;
        queue<pair<int, int>> q;

        temp.push_back({ cr,cc });
        q.push({ cr,cc });
        is_visited[cr][cc] = true;

        while (!q.empty())
        {
            cr = q.front().first;
            cc = q.front().second;
            q.pop();

            for (int i = 0; i < 4; ++i)
            {
                nr = cr + dr[i];
                nc = cc + dc[i];
                if (OutOfBounds(nr, nc) || is_visited[nr][nc])
                    continue;
                if (cave[nr][nc] == false)
                    continue;

                is_visited[nr][nc] = true;
                q.push({ nr,nc });
                temp.push_back({ nr,nc });
            }
        }

        need_to_fall_minerals.push_back(temp);
    }
}

bool ThrowStick(int pos, bool way_to_right)
{
    if (way_to_right)
    {
        for (int c = 1; c <= C; ++c)
        {
            if (cave[pos][c])
            {
                cave[pos][c] = false;
                FindMinerals(pos, c);
                return true;
            }
        }
    }
    else
    {
        for (int c = C; c >= 1; --c)
        {
            if (cave[pos][c])
            {
                cave[pos][c] = false;
                FindMinerals(pos, c);
                return true;
            }
        }
    }

    return false;
}

void FallingMineral(int idx)
{
    vector<pair<int, int>>& cluster = need_to_fall_minerals[idx];

    int r, c;
    //erase the cluster
    for (pair<int, int> next : cluster)
    {
        tie(r, c) = next;
        cave[r][c] = false;
    }

    int drop_dist = 1;
    bool stop_falling = false;
    while (true)
    {
        for (pair<int, int> next : cluster)
        {
            tie(r, c) = next;
            if (r + drop_dist > R || cave[r + drop_dist][c])
            {
                stop_falling = true;
                --drop_dist;
                break;
            }
        }

        if (stop_falling)
            break;
        ++drop_dist;
    }

    for (pair<int, int> next : cluster)
    {
        //update the cluster
        tie(r, c) = next;
        cave[r + drop_dist][c] = true;
    }
}

void Solution()
{
    bool way_to_right = true;
    for (int pos : pos_throw)
    {
        if (ThrowStick(pos, way_to_right))
        {
            int size = need_to_fall_minerals.size();
            for (int i = 0; i < size; ++i)
            {
                FallingMineral(i);
            }
        }

        /*print_cave();
        cout << "\n";*/
        way_to_right = !way_to_right;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();
    print_cave();

    return 0;
}