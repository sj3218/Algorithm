#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

#define INF 0X7FFFFFFF
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    priority_queue<int> greater_q;
    priority_queue<int, vector<int>, greater<int>> less_q;
    
    cin >> N;
    int num;
    int greater_size, less_size;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;

        greater_size = greater_q.size();
        less_size = less_q.size();

        if (greater_size <= less_size)
        {
            greater_q.push(num);
        }
        else
        {
            less_q.push(num);
        }

        if (!less_q.empty())
        {
            int g = greater_q.top();
            int l = less_q.top();
            if (g > l)
            {
                greater_q.pop();
                less_q.pop();
                greater_q.push(l);
                less_q.push(g);
            }
        }

        cout << greater_q.top()<<"\n";
    }

    return 0;
}