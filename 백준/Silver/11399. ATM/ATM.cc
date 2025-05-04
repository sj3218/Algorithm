#include <iostream>
#include <algorithm>

using namespace std;
int N;
int time[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i = 0; i< N; ++i)
    {
        cin >> time[i];
    }
    
    int answer = 0;
    int sum = 0;
    sort(time, time + N);
    
    for(int i = 0; i< N; ++i)
    {
        sum += time[i];
        answer += sum;
    }
    
    cout << answer;
    return 0;
}