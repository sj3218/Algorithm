#include <iostream>
#include <algorithm>
#define NOT_VISITIED -1
#define IN_CYCLE 0
using namespace std;

int Test_Case;
int N;
int board[100001];
int is_visited[100001];

void bfs(int start_idx)
{
    int nx = start_idx;

    while (true)
    {
        is_visited[nx] = start_idx;
        nx = board[nx];

        if (is_visited[nx] == start_idx)
        {
            while (is_visited[nx] != IN_CYCLE)
            {
                is_visited[nx] = IN_CYCLE;
                nx = board[nx];
            }
            break;
        }

        if (is_visited[nx] != NOT_VISITIED)
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> Test_Case;
    for (int i = 0; i < Test_Case; ++i)
    {
        int answer = 0;

        fill_n(is_visited, 100001, NOT_VISITIED);

        cin >> N;
        for (int j = 1; j <= N; ++j)
        {
            cin >> board[j];
        }

        for (int j = 1; j <= N; ++j)
        {
            if(is_visited[j] == NOT_VISITIED)
                bfs(j);
        }

        for (int j = 1; j <= N; ++j)
        {
            if (is_visited[j] != IN_CYCLE)
                ++answer;
        }

        cout << answer << "\n";
    }

    return 0;
}