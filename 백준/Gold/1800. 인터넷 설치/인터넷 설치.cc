#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0x7fffffff

using namespace std;

int N, P, K;
vector<vector<pair<int, int>>> cost_of_network(1001);
int d[1001];// 유선 쓴 개수
int answer = -1;

//mid = 최대 비용
bool dijkstra(int mid)
{
    fill_n(d, 1001, INF);
    d[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0,1 }); // cnt_used , pos

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_w = pq.top().first;
        pq.pop();

        if (d[cur] < cur_w)
            continue;

        for (pair<int, int> next : cost_of_network[cur])
        {
            int next_w = cur_w;

            if (next.second > mid)
            {
                next_w += 1;
            }

            if (next_w < d[next.first])
            {
                d[next.first] = next_w;
                pq.push({ next_w, next.first });
            }
        }
    }

    return d[N] <= K;
}

void Solution()
{
    int start = 0;
    int end = 1000000;
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (dijkstra(mid))
        {
            //가능 하면 end를 mid로
            end = mid - 1;
            answer = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> P >> K;

    int x, y, cost;
    for (int i = 0; i < P; ++i)
    {
        cin >> x >> y >> cost;
        cost_of_network[x].push_back({ y,cost });
        cost_of_network[y].push_back({ x, cost });
    }

    Solution();
    cout << answer;

    return 0;
}