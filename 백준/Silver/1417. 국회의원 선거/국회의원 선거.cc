#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, dasom;
    cin >> n;
    cin >> dasom;
    int val;
    priority_queue<int> q;
    
    for(int i = 1; i< n; ++i)
    {
        cin >> val;
        if(val >= dasom)
        {
            q.push(val);
        }
    }
    
    int ans = 0;
    while(!q.empty() && q.top() >= dasom)
    {
        val = q.top();
        q.pop();
        val--;
        dasom++;
        q.push(val);
        ans++;
    }
    cout <<ans;
    return 0;
}