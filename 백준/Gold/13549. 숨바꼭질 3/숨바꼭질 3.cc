#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int dp[100001];
const int INF = 0XFFFFFFF;

bool CanDo(int value)
{
    if (value < 0 || value > 100000)
        return false;
    return true;
}
void bfs()
{
    fill_n(dp, 100001, INF);
    queue<int> q;
    q.push(N);
    dp[N] = 0;
    
    int curr_pos;
    int curr_time;
    int value[3] = { 0,0,0 };
    while (!q.empty())
    {
        curr_pos = q.front(); q.pop();
        if (curr_pos == K)
        {
            cout << dp[curr_pos];
            return;
        }
        curr_time = dp[curr_pos];

        value[0] = curr_pos - 1;
        value[1] = curr_pos + 1;
        value[2] = curr_pos * 2;

        for (int i = 0; i < 3; ++i)
        {
            if (!CanDo(value[i]))
            {
                continue;
            }

            if (i != 2)
            {
                if (dp[value[i]] != INF && dp[value[i]] <= curr_time+1)
                    continue;
                dp[value[i]] = curr_time+1;
            }
            else
            {
                if (dp[value[i]] != INF && dp[value[i]] <= curr_time)
                    continue;
                dp[value[i]] = curr_time;
            }

            q.push(value[i]);
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> K;
    bfs();

    return 0;
}