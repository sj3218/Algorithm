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

int N;
int arr[100001];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long answer = 0;

    cin >> N;
    
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    int a, b;
    while (pq.size() > 1)
    {
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();

        a += b;
        answer += a;
        pq.push(a);
    }

    cout << answer;
    return 0;
}