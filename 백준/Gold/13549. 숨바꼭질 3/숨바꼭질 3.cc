
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int dist[100001];
int cnt[100001];

void bfs()
{
    queue<int> q;
    q.push(N);
    dist[N] = 0;
    cnt[N] = 1;

    int curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        for (int nx : { curr - 1, curr + 1, curr * 2 })
        {
            if (nx < 0 || nx > 100000)
                continue;

            if (dist[nx] == -1 || dist[nx] > dist[curr])
            {
                if (nx != curr * 2)
                {
                    dist[nx] = dist[curr] + 1;
                }
                else
                {
                    dist[nx] = dist[curr];
                }
                
                q.push(nx);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    fill_n(dist, 100001, -1);

    bfs();

    cout << dist[K];

    return 0;
}
