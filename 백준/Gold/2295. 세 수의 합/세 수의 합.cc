#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[1001];
vector<int> two_sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            two_sum.push_back(arr[i] + arr[j]);
        }
    }

    sort(two_sum.begin(), two_sum.end());

    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (binary_search(two_sum.begin(), two_sum.end(), arr[i] - arr[j]))
            {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}