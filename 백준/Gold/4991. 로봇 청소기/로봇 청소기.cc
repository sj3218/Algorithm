#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

#define INF 0X7FFFFFFF
#define CLEAN_CELL 1
#define DIRTY_CELL 2
#define FURNITURE_CELL 3

using namespace std;

int w, h;
int board[21][21];
vector<pair<int, int>> dirty_points;
int dist[21][21]; // idx -> i까지의 거리
int dp[21][21];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

bool Input()
{
    string s;
    cin >> w >> h;
    dirty_points.clear();
    fill_n(&board[0][0], 21 * 21, 0);
    fill_n(&dist[0][0], 21 * 21, 0);

    if (w == 0 && h == 0)
        return false;


    for (int i = 1; i <= h; ++i)
    {
        cin >> s;
        for (int j = 1; j <= w; ++j)
        {
            if (s[j - 1] == '.')
                board[i][j] = CLEAN_CELL;
            else if (s[j - 1] == '*')
            {
                dirty_points.push_back({ i,j });
                board[i][j] = DIRTY_CELL;
            }
            else if (s[j - 1] == 'x')
                board[i][j] = FURNITURE_CELL;
            else
                dirty_points.insert(dirty_points.begin(), { i,j });
        }
    }

    return true;
}

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > h || c > w)
        return true;
    return false;
}

bool bfs(int idx)
{
    fill_n(&dp[0][0], 21 * 21, -1);
    queue<pair<int, int>> q;
    int cr, cc;
    cr = dirty_points[idx].first;
    cc = dirty_points[idx].second;
    q.push({ cr,cc });
    dp[cr][cc] = 0;
    
    int nr, nc;
    while (!q.empty())
    {
        cr = q.front().first;
        cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            nr = cr + dr[i];
            nc = cc + dc[i];
            if (OutOfBound(nr, nc) || board[nr][nc] == FURNITURE_CELL || dp[nr][nc] != -1)
                continue;

            dp[nr][nc] = dp[cr][cc] + 1;
            q.push({ nr,nc });
        }
    }

    int size = dirty_points.size();
    for (int i = 0; i < size; ++i)
    {
        tie(cr, cc) = dirty_points[i];
        if (dp[cr][cc] == -1)
            return false;

        dist[idx][i] = dp[cr][cc];
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    bool can_clean_all_dirty = true;
    vector<int> order;
    int ans = INF;
    int size;
    int sum = 0;
    int prev = 0;
    int cur = 0;

    while (Input())
    {
        can_clean_all_dirty = true;
        order.clear();
        ans = INF;

        size = dirty_points.size();
        for (int i = 0; i < size; ++i)
        {
            order.push_back(i);
            if (!bfs(i))
            {
                can_clean_all_dirty = false;
                break;
            }
        }

        if (can_clean_all_dirty == false)
        {
            cout << "-1\n";
            continue;
        }

        do
        {
            sum = 0;
            prev = 0;

            for (int i = 0; i < size; ++i)
            {
                cur = order[i];
                sum += dist[prev][cur];
                prev = cur;
            }

            ans = min(ans, sum);
        } while (next_permutation(order.begin()+1, order.end()));
        cout << ans<<"\n";
    }

    return 0;
}