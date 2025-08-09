#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <map>

using namespace std;
#define INF 0X7FFFFFFF

int N, M;
int arr1[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr1[i];
    }
    
    sort(arr1, arr1 + N);
    int num;
    int idx;

    cin >> M;
    for (int j = 0; j < M; ++j)
    {
        cin >> num;

        idx = lower_bound(arr1, arr1 + N, num) - arr1;
        if (idx >= N)
        {
            cout << "0\n";
            continue;
        }

        if(arr1[idx] != num)
            cout << "0\n";
        else
            cout << "1\n";

    }

    return 0;
}