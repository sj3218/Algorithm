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

bool between(long long a, long long b, long long c)
{
    if (a > b)
        swap(a, b);
    return a <= c && c <= b;
}

bool Collinear(Point a, Point b, Point c)
{
    return between(a.x, b.x, c.x) && between(a.y, b.y, c.y);
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

    int c1 = CCW(points[0], points[1], points[2]);
    int c2 = CCW(points[0], points[1], points[3]);
    int c3 = CCW(points[2], points[3], points[0]);
    int c4 = CCW(points[2], points[3], points[1]);
    bool intersect = false;
    if (c1 * c2 < 0 && c3 * c4 < 0)
    {
        intersect = true;
    }
    else
    {
        if (c1 == 0 && Collinear(points[0], points[1], points[2]))
            intersect = true;
        else if (c2 == 0 && Collinear(points[0], points[1], points[3]))
            intersect = true;
        else if (c3 == 0 && Collinear(points[2], points[3], points[0]))
            intersect = true;
        else if (c4 == 0 && Collinear(points[2], points[3], points[1]))
            intersect = true;
    }

    if (intersect)
        cout << 1;
    else
        cout << 0;

    return 0;
}