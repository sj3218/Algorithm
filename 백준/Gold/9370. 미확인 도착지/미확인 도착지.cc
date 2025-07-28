#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

#define INF 0X7FFFFFFF
using namespace std;

int test_case;
int point_cnt, street_cnt, goal_cnt;
int start_point, detection_start_point, detection_end_point;
int a, b, dist;
vector<int> destination_candidate;
vector < vector<pair<int, int>>> city(2001);
vector<int> answer;
int cost[2][2001]; //0: not reached, 1: reached

void Input()
{
    answer.clear();
    destination_candidate.clear();
    city.clear();
    city = vector<vector<pair<int, int>>>(2001);
    fill_n(&cost[0][0], 2001*2, INF);

    cin >> point_cnt >> street_cnt >> goal_cnt;
    cin >> start_point >> detection_start_point >> detection_end_point;

    for (int i = 0; i < street_cnt; ++i)
    {
        cin >> a >> b >> dist;
        city[a].push_back({ b,dist });
        city[b].push_back({ a,dist });
    }

    int goal;
    for (int i = 0; i < goal_cnt; ++i)
    {
        cin >> goal;
        destination_candidate.push_back(goal);
    }
}

void dijkstra()
{
    priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;
    pq.push({ 0,start_point, false }); //cost, pos, not reached
    cost[0][start_point] = 0;

    int curr_pos, curr_cost, next_pos, next_cost, curr_reached, next_reached;
    while (!pq.empty())
    {
        tie(curr_cost, curr_pos, curr_reached) = pq.top();
        pq.pop();

        for (pair<int, int> next : city[curr_pos])
        {
            tie(next_pos, next_cost) = next;

            if (!curr_reached)
            {
                if ((detection_end_point == next_pos && detection_start_point == curr_pos) ||
                    (detection_end_point == curr_pos && detection_start_point == next_pos))
                {
                    next_reached = true;
                }
                else
                    next_reached = false;
            }
            else
                next_reached = true;

            next_cost += curr_cost;
            if (cost[next_reached][next_pos] <= next_cost)
                continue;

            
            cost[next_reached][next_pos] = next_cost;
            pq.push({ next_cost, next_pos, next_reached });
        }
    }
}

void PrintAnswer()
{
    sort(destination_candidate.begin(), destination_candidate.end());
    int size = destination_candidate.size();
    int idx;
    for (int i = 0; i < size; ++i)
    {
        idx = destination_candidate[i];

        if (cost[1][idx] != INF)
        {
            if(cost[1][idx] <= cost[0][idx])
                cout << idx <<" ";
        }
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> test_case;

    for (int i = 0; i < test_case; ++i)
    {
        Input();
        dijkstra();
        PrintAnswer();
    }

    return 0;
}