#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int temperature[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> temperature[i];
    }

    int sum = 0;
    for (int i = 0; i < K; ++i)
    {
        sum += temperature[i];
    }

    int answer = sum;
    for (int i = K, j = 0; i < N; ++i, ++j)
    {
        sum -= temperature[j];
        sum += temperature[i];
        answer = max(answer, sum);
    }

    cout << answer;

    return 0;
}