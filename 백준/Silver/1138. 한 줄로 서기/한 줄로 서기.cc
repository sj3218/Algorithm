#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int N;
int is_visited[11];

void find_num(int x, int num)
{
    int i = 0;
    int cnt = 0;

    while (true)
    {
        if (is_visited[i] != 0)
        {
            ++i;
            continue;
        }

        if (cnt == x)
        {
            is_visited[i] = num;
            break;
        }
        ++i;
        ++cnt;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int x;
    for (int i = 1; i <= N; ++i)
    {
        cin >> x;
        find_num(x, i);
    }

    for (int i = 0; i < N; ++i)
    {
        cout << is_visited[i]<<" ";
    }
    return 0;
}