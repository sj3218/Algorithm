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

pair<int, int> points[3];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    for (int i = 0; i < 3; ++i)
    {
        cin >> x >> y;
        points[i] = { x,y };
    }

    pair<int, int> vec1 = { points[0].first - points[1].first, points[0].second - points[1].second };
    pair<int, int> vec2 = { points[0].first - points[2].first, points[0].second - points[2].second };
    int cross_product = vec1.first * vec2.second - vec1.second * vec2.first;
    if (cross_product > 0)
        cout << 1;
    else if (cross_product == 0)
        cout << 0;
    else
        cout << -1;

    return 0;
}