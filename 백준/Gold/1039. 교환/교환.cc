#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

#define INF 0X7FFFFFFF
using namespace std;
int N, K;
int answer = -1;
int is_visited[11][1000001];

void bfs()
{
    queue<pair<int, string>> q;
    q.push({ 0, to_string(N)});
    is_visited[0][N] = true;

    int depth;
    string num;
    string next_num;
    int size = to_string(N).size();

    while (!q.empty())
    {
        tie(depth, num) = q.front();
        q.pop();

        if (depth == K)
        {
            answer = max(answer, stoi(num));
            continue;
        }

        for (int i = 0; i < size; ++i)
        {
            for (int j = i + 1; j < size; ++j)
            {
                next_num = num;
                swap(next_num[i], next_num[j]);
                if (next_num[0] == '0')
                    continue;

                if (!is_visited[depth + 1][stoi(next_num)])
                {
                    is_visited[depth + 1][stoi(next_num)] = true;
                    q.push({ depth + 1, next_num });
                }
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