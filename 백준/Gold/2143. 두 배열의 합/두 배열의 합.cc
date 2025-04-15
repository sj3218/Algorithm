#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, M;
long long arrA[1001];
long long arrB[1001];
long long answer = 0;

long long dpA[1001];
long long dpB[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arrA[i];
        dpA[i] = dpA[i - 1] + arrA[i];
    }
    cin >> M;
    for (int i = 1; i <= M; ++i)
    {
        cin >> arrB[i];
        dpB[i] = dpB[i - 1] + arrB[i];
    }

    vector<long long> vecA;
    vector<long long> vecB;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            vecA.push_back(dpA[i] - dpA[j]);
        }
    }
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            vecB.push_back(dpB[i] - dpB[j]);
        }
    }

    sort(vecA.begin(), vecA.end());
    sort(vecB.begin(), vecB.end());

    int sum;
    for (int i = 0; i < vecA.size(); ++i)
    {
        sum = T - vecA[i];
        answer += upper_bound(vecB.begin(), vecB.end(), sum) - lower_bound(vecB.begin(), vecB.end(), sum);
    }

    cout << answer;
    return 0;
}