#include <iostream>
#include <algorithm>
#include <vector>

#define INF 0x7fffffff
#define PLUS 0
#define MINUS 1
#define MULTIPLE 2
#define DIVIDE 3

using namespace std;

int N;
int nums[101];
int max_answer = -INF;
int min_answer = INF;

void dfs(int idx, int current, int plus, int minus, int mul, int div)
{
    if (idx == N)
    {
        max_answer = max(max_answer, current);
        min_answer = min(min_answer, current);
        return;
    }

    int next_num = nums[idx];

    if (plus > 0)
    {
        dfs(idx + 1, current + next_num, plus - 1, minus, mul, div);
    }
    if (minus > 0)
    {
        dfs(idx + 1, current - next_num, plus, minus - 1, mul, div);
    }
    if (mul > 0)
    {
        dfs(idx + 1, current * next_num, plus, minus, mul - 1, div);
    }
    if (div > 0)
    {
        dfs(idx + 1, current / next_num, plus, minus, mul, div - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }
    int plus, minus, mul, div;
    cin >> plus >> minus >> mul >> div;

    dfs(1, nums[0], plus, minus, mul, div);

    cout << max_answer << "\n" << min_answer;
    return 0;
}