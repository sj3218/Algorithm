#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int cnt;

priority_queue<int, vector<int>, greater<>> less_pq;
priority_queue<int> greater_pq;
int nums[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int latest_pop_num = -10001;
    
    cin >> cnt;
    int greater_size, less_size;
    for (int i = 0; i < cnt; ++i)
    {
        cin >> nums[i];
        greater_size = greater_pq.size();
        less_size = less_pq.size();
        
        if (less_size >= greater_size)
            greater_pq.push(nums[i]);
        else
            less_pq.push(nums[i]);

        if (less_pq.size() != 0)
        {
            if (greater_pq.top() > less_pq.top())
            {
                int g = greater_pq.top();
                int l = less_pq.top();
                greater_pq.pop();
                less_pq.pop();
                greater_pq.push(l);
                less_pq.push(g);
            }
        }
        
        cout << greater_pq.top() <<"\n";
    }
    return 0;
}