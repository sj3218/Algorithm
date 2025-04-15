#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    vector<int> answer;
    answer.push_back(arr[0]);
    int last_value = arr[0];
    for (int i = 1; i < N; ++i)
    {
        if (last_value < arr[i])
        {
            answer.push_back(arr[i]);
            last_value = arr[i];
        }
        else if (last_value > arr[i])
        {
            int idx = lower_bound(answer.begin(), answer.end(), arr[i]) - answer.begin();
            answer[idx] = arr[i];
            if (idx == answer.size() - 1)
                last_value = arr[i];
        }
    }

    cout << answer.size();
    return 0;
}