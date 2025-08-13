#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int V, E;
int cost[401][401];
bool is_visited[401];
int answer = INF;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> V >> E;
    int a, b, c;

    fill_n(&cost[0][0], 401 * 401, INF);
    for (int i = 0; i < E; ++i)
    {
        cin >> a >> b >> c;
        cost[a][b] = c;
    }

    for (int k = 1; k <= V; ++k)//경유지
    {
        for (int i = 1; i <= V; ++i)//start
        {
            for (int j = 1; j <= V; ++j)//end
            {
                if (i == j)
                {
                    cost[i][j] = 0;
                    continue;
                }

                if (cost[i][k] != INF && cost[k][j] != INF)
                {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (i == j)
                continue;

            if (cost[i][j] == INF || cost[j][i] == INF)
                continue;
            answer = min(answer, cost[i][j] + cost[j][i]);
        }
    }

    if (answer == INF)
        cout << -1;
    else
        cout << answer;
    return 0;
}