#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
priority_queue<long long , vector<long long>, greater<long long>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    long long val;
    for(int i = 0; i< N; ++i)
    {
        cin >> val;
        pq.push(val);
    }
    
    for(int i = 0; i< M; ++i)
    {
        long long a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        
        pq.push(a+ b);
        pq.push(a+ b);
    }
    
    long long ans = 0;
    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    
    cout << ans;
    return 0;
}