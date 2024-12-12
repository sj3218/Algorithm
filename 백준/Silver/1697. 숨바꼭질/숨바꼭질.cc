#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int is_visited[100001];

void bfs()
{
    queue<int> q;
    q.push(N);
    is_visited[N] = 1;

    int curr;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        int time = is_visited[curr];

        if (curr == K)
        {
            break;
        }

        if ((curr-1) >= 0 && !is_visited[curr - 1])
        {
            is_visited[curr - 1] = time + 1;
            q.push(curr - 1);
        }

        if ((curr + 1) <= 100000 && !is_visited[curr + 1])
        {
            is_visited[curr + 1] = time + 1;
            q.push(curr + 1);
        }

        if ((curr*2) <= 100000 && !is_visited[curr * 2])
        {
            is_visited[curr * 2] = time + 1;
            q.push(curr * 2);
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    fill_n(is_visited, 100001, 0);
    bfs();

    cout << is_visited[K] - 1;

    return 0;
}