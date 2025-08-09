#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
//#define INF 0X7FFFFFFF
const long long INF = 1E18;
int N, M, K;
vector<vector<pair<int, int>>> street_info(10001);
long long cost[10001][21];

void Input()
{
    fill_n(&cost[0][0], 10001 * 21, INF);
    cin >> N >> M >> K;
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        street_info[a].push_back({ b,c });
        street_info[b].push_back({ a,c });
    }
}

long long dijkstra()
{
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;//cost, pos, used
    pq.push({ 0,1,0 });
    cost[1][0] = 0;

    int c, x, used;
    int nx, nc;
    while (!pq.empty())
    {
        tie(c, x, used) = pq.top();
        pq.pop();

        if (c > cost[x][used])
            continue;

        for (pair<int, int> next : street_info[x])
        {
            tie(nx, nc) = next;

            if (cost[nx][used] > cost[x][used] + nc)
            {
                cost[nx][used] = cost[x][used] + nc;
                pq.push({ cost[nx][used], nx, used });
            }

            if (used + 1 <= K)
            {
                if (cost[nx][used + 1] > cost[x][used])
                {
                    cost[nx][used + 1] = cost[x][used];
                    pq.push({ cost[nx][used + 1], nx, used + 1 });
                }
            }

        }
    }

    long long answer = INF;
    for (int i = 0; i <= K; ++i)
    {
        answer = min(answer, cost[N][i]);
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    cout << dijkstra();

    return 0;
}