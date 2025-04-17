#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, d, k, c;
int dishes[30001 * 2];
int answer = 0;
int cnt_sushi[3001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; ++i)
    {
        cin >> dishes[i];
        dishes[N + i] = dishes[i];
    }

    ++answer;
    ++cnt_sushi[c]; //coupon

    int start = 0;
    int end = 0;
    int cnt_kind = 1;

    for (end = 0; end < k; ++end)
    {
        if (cnt_sushi[dishes[end]] == 0)
        {
            ++cnt_kind;
            ++answer;
        }

        ++cnt_sushi[dishes[end]];
    }

    while (start < end && end < N*2)
    {
        --cnt_sushi[dishes[start]];
        if (cnt_sushi[dishes[start]] == 0)
        {
            --cnt_kind;
        }
        ++start;
        
        //eat
        if (cnt_sushi[dishes[end]] == 0)
        {
            ++cnt_kind;
            answer = max(answer, cnt_kind);
        }
        ++cnt_sushi[dishes[end]];
        ++end;
    }

    cout << answer;
    return 0;
}