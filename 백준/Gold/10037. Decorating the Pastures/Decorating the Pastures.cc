#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
#define F 1
#define J 2

int cnt_pastures, cnt_path;
//vector<vector<int>> pastures(50001);
vector<set<int>> pastures(50001);
int answer = 0;
int is_visited[50001];

vector<int> bfs(int idx)
{
    vector<int> visited_pastures;
    queue<int> q;
    q.push(idx);
    visited_pastures.push_back(idx);
    is_visited[idx] = J;

    int curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        for (int next : pastures[curr])
        {
            if (is_visited[next] != 0)
            {
                if (is_visited[next] == is_visited[curr])
                    return vector<int>();

                continue;
            }

            is_visited[next] = (is_visited[curr] == F ? J : F);
            q.push(next);
            visited_pastures.push_back(next);
        }
    }

    return visited_pastures;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> cnt_pastures >> cnt_path;
    int a, b;
    for (int i = 0; i < cnt_path; ++i)
    {
        cin >> a >> b;
        pastures[a].insert(b);
        pastures[b].insert(a);
    }

    int cnt_J = 0;
    int cnt_visited_pastures = 0;
    int visited_pastures_size = 0;
    vector<int> visited_pastures;
    for (int i = 1; i <= cnt_pastures; ++i)
    {
        cnt_visited_pastures = 0;
        cnt_J = 0;
        if (is_visited[i] == 0)
        {
            visited_pastures = bfs(i);
            visited_pastures_size = visited_pastures.size();
            if (visited_pastures_size == 0)
            {
                answer = -1;
                break;
            }

            for (int next : visited_pastures)
            {
                if (is_visited[next] == J)
                    ++cnt_J;
            }
            answer += max(cnt_J, visited_pastures_size - cnt_J);
        }
    }

    cout << answer;
    return 0;
}
