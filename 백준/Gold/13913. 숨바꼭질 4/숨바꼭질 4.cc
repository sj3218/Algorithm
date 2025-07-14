#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int N, K;
pair<int, int> is_visited[100001];//time, parent

bool OutOfBound(int pos)
{
    if (pos < 0 || pos > 100000)
        return true;
    return false;
}

void bfs()
{
    queue<int> q;
    q.push(N);
    for (int i = 0; i <= 100000; ++i)
    {
        is_visited[i] = { INF, -1 };
    }
    is_visited[N] = {0, -1};

    int curr_pos;
    int curr_time;
    int next_pos;
    while (!q.empty())
    {
        curr_pos = q.front();
        q.pop();
        curr_time = is_visited[curr_pos].first;
        if (curr_pos == K)
            break;

        for (int next_pos : {curr_pos + 1, curr_pos - 1, curr_pos * 2})
        {
            if (OutOfBound(next_pos))
                continue;

            if (is_visited[next_pos].first > curr_time + 1)
            {
                is_visited[next_pos] = { curr_time + 1, curr_pos };
                q.push(next_pos);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    bfs();

    vector<int> parent;
    int curr_pos = K;

    while (curr_pos != -1)
    {
        parent.push_back(curr_pos);
        curr_pos = is_visited[curr_pos].second;
    }

    cout << is_visited[K].first <<"\n";
    int size = parent.size();
    for (int i = size - 1; i >= 0; --i)
    {
        cout << parent[i] << " ";
    }

    return 0;
}