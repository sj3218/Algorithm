#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int N;
long long answer = 0;
vector<vector<int>> info(200001);
priority_queue<int> noodles;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N;
    int deadline, cnt;
    int max_deadline = -1;
    for (int i = 1; i <= N; ++i)
    {
        cin >> deadline >> cnt;
        info[deadline].push_back(cnt);
        max_deadline = max(max_deadline, deadline);
    }

    for (int i = max_deadline; i > 0; --i)
    {
        for (int noodle : info[i])
        {
            noodles.push(noodle);
        }

        if (noodles.empty())
            continue;

        answer += noodles.top();
        noodles.pop();
    }

    cout << answer;
    return 0;
}
