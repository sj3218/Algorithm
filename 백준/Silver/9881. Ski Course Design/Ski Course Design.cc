#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX_LAW 17
#define INF 0X7FFFFFFF

int cnt_hills;
int hills[1001];

int solution(int high, int low)
{
    int cost = 0;
    int value;
    for (int i = 1; i <= cnt_hills; ++i)
    {
        if (hills[i] > high)
        {
            value = hills[i] - high;
            value *= value;
            cost += value;
        }
        else if (hills[i] < low)
        {
            value = low - hills[i];
            value *= value;
            cost += value;
        }

    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> cnt_hills;

    int max_height = 0;
    int min_height = INF;
    for (int i = 1; i <= cnt_hills; ++i)
    {
        cin >> hills[i];
        max_height = max(max_height, hills[i]);
        min_height = min(min_height, hills[i]);
    }

    int high;
    int answer = INF;
    for (int i = min_height; i <= max_height; ++i)
    {
        high = i + MAX_LAW;

        answer = min(answer, solution(high, i));
    }

    cout << answer;

    return 0;
}
