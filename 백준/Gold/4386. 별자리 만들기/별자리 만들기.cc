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

int star_cnt;
vector<pair<float, float>> positions;
vector<tuple<float, int, int>> edges;
int parent[101];

float distance(int idx_a, int idx_b)
{
    float x = positions[idx_a].first - positions[idx_b].first;
    float y = positions[idx_a].second - positions[idx_b].second;
    float dist = x * x + y * y;
    return dist;
}

int Find(int x)
{
    while (parent[x] >= 0)
    {
        x = parent[x];
    }
    return x;
}

bool Union_(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y)
    {
        return false;
    }

    if (parent[x] == parent[y])
        parent[x]--;

    if (parent[x] < parent[y])
        parent[y] = x;
    else
        parent[x] = y;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(parent, 101, -1);
    float x, y;
    cin >> star_cnt;
    for (int i = 0; i < star_cnt; ++i)
    {
        cin >> x >> y;
        positions.push_back({ x,y });
    }

    float dist;
    for (int i = 0; i < star_cnt; ++i)
    {
        for (int j = i + 1; j < star_cnt; ++j)
        {
            dist = distance(i, j);
            edges.push_back({ dist, i, j });
        }
    }

    sort(edges.begin(), edges.end());

    int cnt = 0;
    int a, b;
    int size = edges.size();
    float answer = 0.f;
    
    for (int i = 0; i < size; ++i)
    {
        tie(dist, a, b) = edges[i];
        if (Union_(a, b))
        {
            ++cnt;
            answer += sqrt(dist);
        }

        if (cnt == star_cnt - 1)
            break;
    }

    cout << fixed << setprecision(2) << answer;
    return 0;
}