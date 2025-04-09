#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
int length[1000001];
int answer = 0;

int CountNieces(int mid)
{
    int cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        cnt += length[i] / mid;
    }

    return cnt;
}

void binarysearch()
{
    int start = 1;
    int end = length[N - 1];

    int mid;
    int cnt;
    while (start <= end)
    {
        mid = (start + end) / 2;
        cnt = CountNieces(mid);

        if (cnt < M)
        {
            end = mid-1;
        }
        else
        {
            start = mid + 1;
            answer = max(answer, mid);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> M >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> length[i];
    }

    sort(length, length + N);

    binarysearch();
    cout << answer;
    return 0;
}