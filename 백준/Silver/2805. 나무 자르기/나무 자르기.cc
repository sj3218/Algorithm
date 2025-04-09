#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int length[1000001];
long answer = 0;

long SumTrees(long mid)
{
    long sum = 0;
    for (int i = 0; i < N; ++i)
    {
        int temp = length[i] - mid;
        if (temp > 0)
        {
            sum += temp;
        }
    }

    return sum;
}

int binarysearch()
{
    long start = 0;
    long end = length[N - 1];
    long mid;
    long total;

    while (start <= end)
    {
        mid = (start + end) / 2;
        total = SumTrees(mid);

        if (total < M)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
            answer = max(answer, mid);
        }
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> length[i];
    }

    sort(length, length + N);

    cout << binarysearch();

    return 0;
}