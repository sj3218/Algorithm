#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

int N, M;
int jem_cnt[300001];

long binary_search(int e)
{
    long start = 1; 
    long end = e;
    long mid;
    long answer = end;

    while (start <= end)
    {
        mid = (start + end) / 2;
        int cnt = 0;

        for (int i = 0; i < M; ++i)
        {
            cnt += jem_cnt[i] / mid;
            if (jem_cnt[i] % mid)
                ++cnt;
        }

        if (cnt <= N)
        {
            end = mid - 1;
            answer = min(answer, mid);
        }
        else
        {
            start = mid + 1;
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> jem_cnt[i];
    }
    int max_cnt = *max_element(jem_cnt, jem_cnt + M);
    cout << binary_search(max_cnt);

    return 0;
}