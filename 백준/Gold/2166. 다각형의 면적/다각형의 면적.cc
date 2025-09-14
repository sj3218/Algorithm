#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
#define INF 0X7FFFFFFF

int N;
double answer = 0;
vector<pair<long long, long long >> points;

void shoelace()
{
    long long a, b, c, d;
    double sum = 0;
    for (int i = 0; i < N-1; ++i)
    {
        tie(a, b) = points[i];
        tie(c, d) = points[i + 1];
        sum += (a * d - b * c);
    }
    sum += points[N - 1].first * points[0].second - points[N - 1].second * points[0].first;

    answer = abs(sum) / 2.f;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cout << fixed << setprecision(1);
    cin >> N;
    int a, b;
    for (int i = 0; i < N; ++i)
    {
        cin >> a >> b;
        points.push_back({ a,b });
    }

    shoelace();
    cout << answer;

    return 0;
}