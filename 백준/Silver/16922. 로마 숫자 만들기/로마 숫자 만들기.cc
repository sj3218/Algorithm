#include <iostream>
#include <set>

using namespace std;

int N;
int values[4] = {1,5,10,50};
set<int> results;

void backtracking(int depth, int sum, int start)
{
    if (depth == N)
    {
        results.insert(sum);
        return;
    }

    for (int i = start; i < 4; ++i)
    {
        backtracking(depth + 1, sum + values[i], i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    backtracking(0, 0, 0);

    cout << results.size();

    return 0;
}