#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;
#define INF 0X7FFFFFFF

long long N;
int K, Q;

long long ParentNode(long long x, long long y)
{
    if (K == 1)
        return abs(x - y);

    unordered_map<long long, int> depth;
    long long px = x;
    long long py = y;
    int dx = 0;
    int dy = 0;

    while (true)
    {
        depth[px] = dx++;
        if (px == 1)
            break;
        px = (px - 2) / K + 1;
    }

    while (true)
    {
        if (depth.count(py))
        {
            return depth[py] + dy;
        }

        ++dy;
        if (py == 1)
            break;
        py = (py - 2) / K + 1;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K >> Q;

    long long x, y;
    for (int i = 0; i < Q; ++i)
    {
        cin >> x >> y;

        cout << ParentNode(x, y) << "\n";
    }
    return 0;
}