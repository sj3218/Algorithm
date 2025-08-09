#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N;
int arr[1000001];
int index[1000001];

bool comp(const pair<int, int>& a, const int& b)
{
    return a.first < b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    fill_n(index, 1000001, -1);

    vector<pair<int, int>> lis;
    lis.push_back({ arr[0], 0 });//value, index
    int last_value = arr[0];
    int value;
    for (int i = 1; i < N; ++i)
    {
        value = arr[i];
        if (last_value < value)
        {
            index[i] = lis[lis.size() - 1].second;
            lis.push_back({ value, i });
            last_value = value;
        }
        else if (last_value > value)
        {
            auto idx = lower_bound(lis.begin(), lis.end(), value, comp) - lis.begin();

            if (idx == 0)
            {
                index[i] = -1;
            }
            else
            {
                index[i] = lis[idx-1].second;
            }

            lis[idx] = { value, i };

            if (idx == lis.size() - 1)
            {
                last_value = value;
            }
        }
    }

    cout << lis.size() << "\n";
    int idx = lis[lis.size() - 1].second;
    vector<int >answer;

    while (idx != -1)
    {
        value = arr[idx];
        answer.push_back(value);
        idx = index[idx];
    }
    reverse(answer.begin(), answer.end());
    for (int a : answer)
    {
        cout << a << " ";
    }

    return 0;
}