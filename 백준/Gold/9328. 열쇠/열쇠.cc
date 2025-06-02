#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

#define KEY_SIZE    (('Z')-('A') + 2)
#define MAX_SIZE    102
using namespace std;

int test_case;
string line;
int H, W;
char board[MAX_SIZE][MAX_SIZE];
int cnt_documents = 0;
bool is_visited[MAX_SIZE][MAX_SIZE];
bool key[KEY_SIZE];
vector<pair<int, int>> entrances;
vector<pair<int, int>> visited_doors;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > H || y > W)
        return false;
    return true;
}

int bfs(int x, int y)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({ x,y });
    char c = board[x][y];
    if ('A' <= c && c <= 'Z')
    {
        if (!key[c - 'A' + 1])
        {
            return 0;
        }
    }
    if (is_visited[x][y])
        return 0;

    is_visited[x][y] = true;

    int cx, cy;
    int nx, ny;
    while (!q.empty())
    {
        cx = q.front().first;
        cy = q.front().second;
        q.pop();

        if (board[cx][cy] == '$')
            ++cnt;

        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (!IsValid(nx, ny) || is_visited[nx][ny])
                continue;

            c = board[nx][ny];
            if (c == '*')
                continue;
             
            if ('A' <= c && c <= 'Z')
            {
                if (!key[c - 'A' + 1])
                {
                    //is_visited[nx][ny] = true;
                    visited_doors.push_back({ nx, ny });
                    continue;
                }
            }

            if ('a' <= c && c <= 'z')
            {
                key[c - 'a' + 1] = true;

                for (auto it = visited_doors.begin(); it != visited_doors.end(); )
                {
                    if (board[it->first][it->second] - 'A' == c - 'a')
                    {
                        q.push(*it);
                        it = visited_doors.erase(it);
                    }
                    else
                        ++it;
                }
            }

            is_visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> test_case;

    while(test_case--)
    {
        fill_n(&board[0][0], MAX_SIZE * MAX_SIZE, '*');
        fill_n(&is_visited[0][0], MAX_SIZE * MAX_SIZE, false);
        fill_n(key, KEY_SIZE, false);
        cnt_documents = 0;
        entrances.clear();
        visited_doors.clear();

        cin >> H >> W;
        char c;
        for (int i = 1; i <= H; ++i)
        {
            cin >> line;
            for (int j = 1; j <= W; ++j)
            {
                c = line[j - 1];
                board[i][j] = line[j - 1];

                if (i == 1 || j == 1 || i == H || j == W)
                {
                    if (c == '*')
                        continue;
                    else if ('A' <= c && c <= 'Z')
                    {
                        visited_doors.push_back({ i,j });
                    }
                    else if ('a' <= c && c <= 'z')
                    {
                        int idx = c - 'a' + 1;
                        key[idx] = true;
                    }

                    entrances.push_back({ i,j });
                }
            }
        }

        cin >> line;
        for (char c : line)
        {
            if (c == '0')
                break;
            int idx = c - 'a' + 1;
            key[idx] = true;
        }

        for (pair<int, int> entrance : entrances)
        {
            cnt_documents += bfs(entrance.first, entrance.second);
        }

        for (pair<int, int> door : visited_doors)
        {
            cnt_documents += bfs(door.first, door.second);
        }

        cout << cnt_documents <<"\n";
    }
    
    return 0;
}