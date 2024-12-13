#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<vector<int>> works;
vector<int> Time;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int time, cnt, num;
    cin >> N;
    works.assign(N, vector<int>());

    for (int i = 0; i < N; ++i)
    {
        cin >> time >> cnt;
        Time.push_back(time);
        
        for (int j = 0; j < cnt; ++j)
        {
            cin >> num;
            works[i].push_back(num);
        }
    }

    int ans = 0;

    for (int i = 0; i < N; ++i)
    {
        int size = works[i].size();
        time = 0;
        for (int j = 0; j < size; ++j)
        {
            time = max(time, Time[works[i][j] - 1]);
        }

        time += Time[i];

        Time[i] = time;
        ans = max(ans, time);
    }

    cout << ans;
    return 0;
}