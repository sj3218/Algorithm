#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

struct Point
{
    long long x, y;
};
Point points[4];

int CCW(Point a, Point b, Point c)
{
    pair<long long, long long> line1 = { b.x - a.x, b.y - a.y };
    pair<long long, long long> line2 = { c.x - a.x, c.y - a.y };

    long long cross_product = line1.first * line2.second - line1.second * line2.first;
    if (cross_product > 0)
        return 1;
    else if (cross_product < 0)
        return -1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long x, y;
    for (int i = 0; i < 4; ++i)
    {
        cin >> points[i].x >> points[i].y;
    }

    if (CCW(points[0], points[1], points[2]) != CCW(points[0], points[1], points[3]))
    {
        if (CCW(points[2], points[3], points[0]) != CCW(points[2], points[3], points[1]))
        {
            cout << 1;
            return 0;
        }
    }

    cout << 0;
    return 0;
}