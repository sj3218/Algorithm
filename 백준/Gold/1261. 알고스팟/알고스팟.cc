#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
#define INF 0X7FFFFFFF

using namespace std;

int N, M;
int board[101][101];
int dist[101][101];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > N || y > M)
        return false;
    return true;
}

void dijkstra()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, {1,1} });

    dist[1][1] = 0;

    int curr_x, curr_y, curr_w;
    while (!pq.empty())
    {
        curr_w = pq.top().first;
        curr_x = pq.top().second.first;
        curr_y = pq.top().second.second;
        pq.pop();

        if (dist[curr_x][curr_y] < curr_w)
            continue;

        int nx_x, nx_y, nx_w;
        for (int i = 0; i < 4; ++i)
        {
            nx_x = curr_x + dx[i];
            nx_y = curr_y + dy[i];
            nx_w = curr_w + board[nx_x][nx_y];

            if (!IsValid(nx_x, nx_y))
                continue;

            if (dist[nx_x][nx_y] <= nx_w)
                continue;

            dist[nx_x][nx_y] = nx_w;
            pq.push({ nx_w, {nx_x, nx_y} });
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(&dist[0][0], 101 * 101, INF);

    cin >> M >> N;
    string s;
    for (int i = 1; i <= N; ++i)
    {
        cin >> s;
        for (int j = 1; j <= M; ++j)
        {
            board[i][j] = s[j - 1] - '0';
        }
    }

    dijkstra();
    cout << dist[N][M];

    return 0;
}