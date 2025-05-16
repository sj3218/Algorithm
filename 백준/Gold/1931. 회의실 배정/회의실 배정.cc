#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0X7FFFFFFF

using namespace std;

int N;
vector<pair<int, int>> meetings;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int s, e;

    for (int i = 0; i < N; ++i)
    {
        cin >> s >> e;
        meetings.push_back({ e,s });
    }

    sort(meetings.begin(), meetings.end());

    int time = meetings[0].first;
    int answer = 1;

    for (int i = 1; i < N; ++i)
    {
        if (time <= meetings[i].second)
        {
            ++answer;
            time = meetings[i].first;
        }
    }

    cout << answer;
    return 0;
}