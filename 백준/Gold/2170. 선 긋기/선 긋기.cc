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

int line_cnt;
vector<pair<int, int>> lines;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    cin >> line_cnt;
    for (int i = 0; i < line_cnt; ++i)
    {
        cin >> x >> y;
        lines.push_back({ x,y });
    }

    long long answer = 0;
    sort(lines.begin(), lines.end());

    int nx, ny;
    tie(x, y) = lines[0];
    for (int i = 1; i < line_cnt; ++i)
    {
        tie(nx, ny) = lines[i];
        if (y >= nx)
            y = max(y, ny);
        else
        {
            answer += (y - x);
            x = nx;
            y = ny;
        }
    }

    answer += y - x;
    cout << answer;
    return 0;
}