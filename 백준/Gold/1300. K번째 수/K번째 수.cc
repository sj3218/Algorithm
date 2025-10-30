#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

long long N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> K;
    
    long long left, right, mid;
    left = 0;
    right = N * N;
    long long answer;

    while (left <= right)
    {
        mid = (left + right) / 2;
        long long cnt = 0;

        for (int i = 1; i <= N; ++i)
        {
            cnt += min(N, mid / i);
        }

        if (cnt < K)
            left = mid + 1;
        else
        {
            answer = mid;
            right = mid - 1;
        }
    }

    cout << answer;
    return 0;
}