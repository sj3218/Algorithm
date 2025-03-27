#include <iostream>
#include <queue>
#define MAX_POINT 100000

using namespace std;

int N, K;
int dp[100001];
int dx[3] = { -1, 1, 2 };

void bfs()
{
    queue<int> q;
    q.push(N);
    dp[N] = 0;

    while (!q.empty())
    {
        int curr_pos = q.front();
        q.pop();

        if (curr_pos == K)
            return;

        int curr_time = dp[curr_pos];

        for (int i = 0; i < 3; ++i)
        {
            int nx = curr_pos;
            if (i == 2)
            {
                nx *= dx[i];
            }
            else
            {
                nx += dx[i];
            }

            if (nx < 0 || nx > MAX_POINT)
            {
                continue;
            }

            if (dp[nx] != 0)
            {
                continue;
            }

            dp[nx] = curr_time + 1;
            q.push(nx);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;

    bfs();
    cout << dp[K];

    return 0;
}