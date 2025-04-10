#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[4][4001];
vector<int> two_sum;
vector<int> two_sum2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin >> arr[j][i];
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            two_sum.push_back(arr[0][i] + arr[1][j]);
            two_sum2.push_back(arr[2][i] + arr[3][j]);
        }
    }

    sort(two_sum.begin(), two_sum.end());
    sort(two_sum2.begin(), two_sum2.end());

    long long answer = 0;
    int size = two_sum.size();
    for (int i = 0; i < size; ++i)
    {
        int lower = lower_bound(two_sum.begin(), two_sum.end(), -two_sum2[i]) - two_sum.begin();
        int upper = upper_bound(two_sum.begin(), two_sum.end(), -two_sum2[i]) - two_sum.begin();
        answer += (upper - lower);
    }

    cout << answer;
    return 0;
}