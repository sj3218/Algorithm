#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> countries(1001);
bool is_visited[1001];

int bfs()
{
    queue<int> q;
    q.push(1);

    is_visited[1] = true;

    int curr;
    int cnt = 0;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        for (int next : countries[curr])
        {
            if (is_visited[next])
                continue;

            is_visited[next] = true;
            q.push(next);
            ++cnt;
        }
    }

    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test_case;
    int kind_of_flights;
    int cnt_countries;

    cin >> test_case;
    int a, b;
    while (test_case--)
    {
        fill_n(is_visited, 1001, false);
        for (vector<int> country : countries)
            country.clear();

        cin >> cnt_countries >> kind_of_flights;
        for (int i = 0; i < kind_of_flights; ++i)
        {
            cin >> a >> b;
            countries[a].push_back(b);
            countries[b].push_back(a);
        }

        cout << cnt_countries-1 <<"\n";
    }

    return 0;
}
