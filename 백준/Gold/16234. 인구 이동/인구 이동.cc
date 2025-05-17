#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#define MAX_BOARD 51
using namespace std;

int N, L, R;
int board[MAX_BOARD][MAX_BOARD];
int is_visited[MAX_BOARD][MAX_BOARD];
vector<int> people;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

bool IsValid(int x, int y)
{
    if (x < 0 || y < 0 || x >= N || y >= N)
        return false;
    return true;
}

void bfs(int x, int y, int idx)
{
    int total_people = 0;
    int total_countries = 0;

    queue<pair<int, int>> q;
    q.push({ x,y });
    is_visited[x][y] = idx;

    int cx, cy, nx, ny;
    int ccnt, ncnt;
    int diff;

    while (!q.empty())
    {
        cx = q.front().first;
        cy = q.front().second;
        ccnt = board[cx][cy];

        total_people += ccnt;
        total_countries++;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];
            ncnt = board[nx][ny];
            diff = abs(ncnt - ccnt);

            if (!IsValid(nx, ny) || is_visited[nx][ny] != -1)
                continue;
            
            if (L <= diff && diff <= R)
            {
                is_visited[nx][ny] = idx;
                q.push({ nx, ny });
            }
        }
    }

    people.push_back(total_people/ total_countries);
}

void print()
{
    cout << "\n";
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> L >> R;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
        }
    }

    int answer = 0;
    int idx = 0;
    int total_countries = N * N;

    while (true)
    {
        people.clear();
        fill_n(&is_visited[0][0], MAX_BOARD * MAX_BOARD, -1);
        idx = 0;

        //open boardline
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (is_visited[i][j] != -1)
                    continue;

                bfs(i, j, idx++);
            }
        }

        if (idx == total_countries)
            break;

        //move people
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                board[i][j] = people[is_visited[i][j]];
            }
        }

        //print();
        ++answer;
    }

    cout << answer;
    return 0;
}