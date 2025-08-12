#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int cnt;
int s, t;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<int, vector<int>, greater<int>> classes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> cnt;
    for (int i = 0; i < cnt; ++i)
    {
        cin >> s >> t;
        pq.push({ s,t });
    }

    int top_time;
    while (!pq.empty())
    {
        tie(s, t) = pq.top(); 
        pq.pop();

        if (classes.empty())
        {
            classes.push(t);
            continue;
        }

        top_time = classes.top();
        if (top_time <= s)
        {
            classes.pop();
            classes.push(t);
        }
        else
        {
            classes.push(t);
        }
    }

    cout << classes.size();
    return 0;
}