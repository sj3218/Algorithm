#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

#define INF 0X7FFFFFFF
using namespace std;

int N, K;
bool is_visited[11][1000001];
int answer = -1;

void bfs()
{
    queue<pair<int, string>> q;
    q.push({ 0, to_string(N) });
    is_visited[0][N] = true;
    int size = to_string(N).size();

    int curr_cnt;
    string curr_num;
    string next_num;
    while (!q.empty())
    {
        tie(curr_cnt, curr_num) = q.front();
        q.pop();

        if (curr_cnt == K)
        {
            answer = max(answer, stoi(curr_num));
            continue;
        }

        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                next_num = curr_num;
                swap(next_num[i], next_num[j]);

                if (next_num[0] == '0')
                    continue;
                if (is_visited[curr_cnt + 1][stoi(next_num)] == true)
                    continue;

                is_visited[curr_cnt + 1][stoi(next_num)] = true;
                q.push({ curr_cnt + 1, next_num });
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
    cout << answer;

    return 0;
}