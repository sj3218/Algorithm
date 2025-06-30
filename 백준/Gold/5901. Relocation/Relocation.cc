#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;
#define INF 0X7FFFFFFF

int town_cnt, path_cnt, visit_town_cnt;
vector<int> has_market;
bool has_market_in_town[10001];

vector<vector<pair<int, int>>> region(10001);
int dist[5][10001];

void Input()
{
    cin >> town_cnt >> path_cnt >> visit_town_cnt;

    int a, b, c;
    for (int i = 0; i < visit_town_cnt; ++i)
    {
        cin >> a;
        has_market.push_back(a);
        has_market_in_town[a] = true;
    }

    for (int i = 0; i < path_cnt; ++i)
    {
        cin >> a >> b >> c;
        region[a].push_back({ b,c });
        region[b].push_back({ a,c });
    }

    fill_n(&dist[0][0], 5 * 10001, INF);
}

void dijkstra(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, has_market[start] });
    dist[start][has_market[start]] = 0;

    int curr, cost;
    int n_cost;
    while (!pq.empty())
    {
        cost = pq.top().first;
        curr = pq.top().second;
        pq.pop();

        for (pair<int, int> next : region[curr])
        {
            n_cost = dist[start][curr] + next.second;
            if (dist[start][next.first] <= n_cost)
                continue;

            dist[start][next.first] = n_cost;
            pq.push({ n_cost, next.first });
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    for (int i = 0; i < visit_town_cnt; ++i)
    {
        dijkstra(i);
    }

    int order[5] = { 0,1,2,3,4 };

    int result = INF;
    for (int farm = 1; farm <= town_cnt; ++farm)
    {
        if (has_market_in_town[farm]) 
            continue; 

        vector<int> order(visit_town_cnt);
        for (int i = 0; i < visit_town_cnt; ++i) order[i] = i;

        do {
            int cost = 0;

            // 농장에서 첫 번째 시장까지
            cost += dist[order[0]][farm];

            // 시장들 사이 이동 거리
            for (int i = 0; i < visit_town_cnt - 1; ++i) {
                cost += dist[order[i]][has_market[order[i + 1]]];
            }

            // 마지막 시장에서 농장으로 복귀
            cost += dist[order[visit_town_cnt - 1]][farm];

            result = min(result, cost);

        } while (next_permutation(order.begin(), order.begin() + visit_town_cnt));
    }

    cout << result;
    return 0;
}