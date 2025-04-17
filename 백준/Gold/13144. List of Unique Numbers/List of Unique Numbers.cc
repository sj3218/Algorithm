#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int arr[100001];
bool is_visited[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    long long answer = 0;
    is_visited[arr[0]] = true;

    int end = 0;
    for (int start = 0; start < N; ++start)
    {
        while (end + 1 < N && !is_visited[arr[end + 1]])
        {
            ++end;
            is_visited[arr[end]] = true;
        }

        answer += end - start + 1;
        is_visited[arr[start]] = false;
    }

    cout << answer;
    return 0;
}