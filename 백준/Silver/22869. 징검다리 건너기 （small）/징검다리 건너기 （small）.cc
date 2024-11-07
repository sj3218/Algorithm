#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

int N, K;
int arr[5001];
bool is_visited[5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    fill_n(is_visited, 5001, false);

    queue<int> q;
    q.push(0);
    is_visited[0] = true;

    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        if (index == N - 1)
        {
            break;
        }

        int val = arr[index];

        for (int i = index + 1; i < N; ++i)
        {
            if ((i - index) * (1 + abs(val - arr[i])) <= K)
            {
                if (is_visited[i] == false)
                {
                    is_visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    if (is_visited[N - 1] == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}