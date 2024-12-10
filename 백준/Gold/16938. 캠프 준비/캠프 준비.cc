#include <iostream>
#include <vector>

using namespace std;
int N, L, R, X;
int ans = 0;

vector<int> level;

void backtracking(int cnt, int total, int start, int min_diff, int max_diff)
{
    if (cnt >= 2)
    {
        if (L <= total && total <= R && (max_diff - min_diff) >= X)
        {
            ++ans;
        }

        if (total > R)
        {
            return;
        }
    }

    for (int i = start; i < N; ++i)
    {
        backtracking(cnt + 1, total + level[i], i + 1, min(min_diff, level[i]), max(max_diff, level[i]));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> L >> R >> X;
    int val;
    for (int i = 0; i < N; ++i)
    {
        cin >> val;
        level.push_back(val);
    }

    backtracking(0, 0, 0, 0x7fffffff, 0);

    cout << ans;

    return 0;
}