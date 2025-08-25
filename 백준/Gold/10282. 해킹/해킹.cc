#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int test_case;
int computer_cnt;
int dependency_cnt;
int hacked_computer;
int a, b, s;
vector<vector<pair<int,int>>> computers;//dependency, second
bool is_visited[10001];

pair<int,int> solution()
{
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({ 0, hacked_computer });

    int _time, computer;
    int next_computer, _next_time;
    int total_time = 0;
    int total_hacked_computer = 0;

    while (!pq.empty())
    {
        tie(_time, computer) = pq.top(); pq.pop();

        if (is_visited[computer])
            continue;

        is_visited[computer] = true;
        
        total_time = _time;
        total_hacked_computer++;

        for (pair<int, int> next : computers[computer])
        {
            tie(next_computer, _next_time) = next;
            if (is_visited[next_computer])
                continue;

            pq.push({ _time + _next_time, next_computer });
        }
    }

    return { total_hacked_computer, total_time };
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> test_case;

    while (test_case--)
    {
        //input
        cin >> computer_cnt >> dependency_cnt >> hacked_computer;
        computers.assign(10001, vector<pair<int,int>>());
        fill_n(is_visited, 10001, false);

        for (int i = 0; i < dependency_cnt; ++i)
        {
            cin >> a >> b >> s;
            computers[b].push_back({ a,s });
        }

        //solution
        pair<int, int> answer = solution();
        cout << answer.first << " " << answer.second << "\n";
    }

    return 0;
}