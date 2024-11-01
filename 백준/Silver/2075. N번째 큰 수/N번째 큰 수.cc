#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int arr[1501][1501];

priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int size = 0;
    for(int i = 0; i< N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
            pq.push(arr[i][j]);
            
            if(pq.size() > N)
            {
                pq.pop();
            }
        }
    }
    
    int val = pq.top();
    
    cout << val;
    return 0;
}