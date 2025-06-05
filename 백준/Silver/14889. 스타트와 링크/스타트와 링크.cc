#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int S[21][21];
int answer = 0x7fffffff;
bool is_visited[21];
int team_size;

void CalcTeam()
{
    int start_team = 0;
    int link_team = 0;

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (is_visited[i] && is_visited[j])
            {
                start_team += S[i][j];
                start_team += S[j][i];
            }
            else if (!is_visited[i] && !is_visited[j])
            {
                link_team += S[i][j];
                link_team += S[j][i];
            }
        }
    }

    int temp = abs(start_team - link_team);
    answer = min(answer, temp);
}

void dfs(int cnt, int idx)
{
    if (cnt == team_size)
    {
        CalcTeam();
        return;
    }

    for (int i = idx; i < N; ++i)
    {
        if (is_visited[i])
            continue;

        is_visited[i] = true;
        dfs(cnt + 1, i + 1);
        is_visited[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> S[i][j];
        }
    }

    team_size = N / 2;

    dfs(0, 0);
    cout << answer;

    return 0;
}