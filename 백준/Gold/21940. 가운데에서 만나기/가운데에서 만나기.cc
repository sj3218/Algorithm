#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
#define INF 0X7FFFFFFF

int city_cnt, street_cnt;
int head_count;
int city_idx[201];
vector<pair<int,int>> street_info[201];
int dist[201][201];
bool is_visited[201];

void Input()
{
    cin >> city_cnt >> street_cnt;
    int a, b, t;
    for (int i = 1; i <= street_cnt; ++i)
    {
        cin >> a >> b >> t;
        street_info[a].push_back({ b,t });
    }

    cin >> head_count;
    for (int i = 0; i < head_count; ++i)
    {
        cin >> city_idx[i];
    }
}

void CalculateDist(int start)
{
    fill_n(is_visited, 201, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    dist[start][start] = 0;

    int ncost, nidx;
    int cost, idx;
    while (!pq.empty())
    {
        tie(cost, idx) = pq.top(); pq.pop();
        
        if (is_visited[idx])
            continue;
        is_visited[idx] = true;
        
        for (pair<int, int> next : street_info[idx])
        {
            tie(nidx, ncost) = next;
            if (is_visited[nidx])
                continue;

            if (dist[start][nidx] != -1 && dist[start][nidx] < ncost + cost)
                continue;

            dist[start][nidx] = ncost + cost;
            pq.push({ dist[start][nidx], nidx });
        }
    }
}

int CalculateMaxDist(int idx)
{
    int live_city_idx;
    int to_, from_;
    int max_value = 0;
    for (int i = 0; i < head_count; ++i)
    {
        live_city_idx = city_idx[i];
        to_ = dist[live_city_idx][idx];
        from_ = dist[idx][live_city_idx];

        if (to_ == -1 || from_ == -1)
            return INF;

        max_value = max(max_value, to_ + from_);
    }
    return max_value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    fill_n(&dist[0][0], 201 * 201, -1);

    for (int i = 1; i <= city_cnt; ++i)
    {
        CalculateDist(i);
    }

    int answer = INF;
    vector<int> min_city;
    int temp;
    for (int i = 1; i <= city_cnt; ++i)
    {
        temp = CalculateMaxDist(i);
        if (answer > temp)
        {
            min_city.clear();
            min_city.push_back(i);
            answer = temp;
        }
        else if (answer == temp)
        {
            min_city.push_back(i);
        }
    }

    for (int next : min_city)
    {
        cout << next << " ";
    }
    return 0;
}