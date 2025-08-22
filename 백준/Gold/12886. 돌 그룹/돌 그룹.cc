#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int A, B, C;
bool is_visited[1501][1501];
int total;

pair<int, int> norm(int a, int b, int c)
{
    int Min = min({ a, b, c });
    int Max = max({ a, b,c });
    return { Min, Max };
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B >> C;
    total = A + B + C;

    queue<pair<int, int>> q;
    pair<int, int> nums;
    int a, b, c;
    int na, nb, nc;
    q.push({ A,B });
    is_visited[A][B] = true;

    while (!q.empty())
    {
        tie(a, b) = q.front(); q.pop();
        c = total - a - b;

        if (a == b && b == c)
        {
            cout << 1;
            return 0;
        }

        for (pair<int, int> next : { make_pair(a, b), make_pair(b, c), make_pair(a,c)})
        {
            if (next.first == next.second)
                continue;
            else if (next.first < next.second)
            {
                na = next.first + next.first;
                nb = next.second - next.first;
            }
            else
            {
                na = next.first - next.second;
                nb = next.second + next.second;
            }

            nc = total - na - nb;

            nums = norm(na, nb, nc);
            if (!is_visited[nums.first][nums.second])
            {
                is_visited[nums.first][nums.second] = true;
                q.push({ nums.first, nums.second });
            }
        }
    }

    cout << 0;
    return 0;
}