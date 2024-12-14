#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N, K;
int dist[100001];
int previous_num[100001];

void bfs()
{
    queue<int> q;
    q.push(N);
    dist[N] = 0;
    previous_num[N] = N;

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
                dist[nx] = dist[curr] + 1;
                previous_num[nx] = curr;

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
    fill_n(previous_num, 100001, -1);

    bfs();

    cout << dist[K] << "\n";

    vector<int> order;
    int curr = K;
    while (curr != N)
    {
        order.push_back(curr);
        curr = previous_num[curr];
    }

    cout << N << " ";
    int size = order.size();
    for (int i = size - 1; i >= 0; --i)
    {
        cout << order[i] << " ";
    }

    return 0;
}
