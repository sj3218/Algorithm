#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
vector<pair<int, int>> eggs(9);
int cnt;
int answer;

void solution(int idx)
{
    if (idx == N)
    {
        answer = max(answer, cnt);
        return;
    }

    if (eggs[idx].first <= 0 || cnt == N - 1)
    {
        solution(idx + 1);
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (idx == i || eggs[i].first <= 0)
            continue;

        eggs[idx].first -= eggs[i].second;
        eggs[i].first -= eggs[idx].second;

        if (eggs[idx].first <= 0)
            ++cnt;
        if (eggs[i].first <= 0)
            ++cnt;

        solution(idx + 1);

        if (eggs[idx].first <= 0)
            --cnt;
        if (eggs[i].first <= 0)
            --cnt;

        eggs[idx].first += eggs[i].second;
        eggs[i].first += eggs[idx].second;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> eggs[i].first;
        cin >> eggs[i].second;
    }

    solution(0);
    cout << answer;
    return 0;
}