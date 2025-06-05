#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 1000001
using namespace std;

int N;
int num_testers[SIZE];
int cnt_main, cnt_assist;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> num_testers[i];
    }
    cin >> cnt_main >> cnt_assist;

    long long answer = N;
    int left, cnt;
    for (int i = 0; i < N; ++i)
    {
        left = num_testers[i] - cnt_main;
        if (left <= 0)
            continue;
        cnt = left / cnt_assist;
        if (left % cnt_assist != 0)
            ++cnt;
        answer += cnt;
    }

    cout << answer;
    return 0;
}