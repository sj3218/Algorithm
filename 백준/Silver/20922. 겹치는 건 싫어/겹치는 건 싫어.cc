#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int arr[200001];
int cnt[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    int start = 0;
    int end = 0;
    int length = 1;
    int answer = 0;

    ++cnt[arr[start]];

    for (; start < N; ++start)
    {
        while (end + 1 < N && cnt[arr[end + 1]] < K)
        {
            ++end;
            ++cnt[arr[end]];
        }

        answer = max(answer, end - start + 1);
        --cnt[arr[start]];
    }

    cout << answer;
    return 0;
}