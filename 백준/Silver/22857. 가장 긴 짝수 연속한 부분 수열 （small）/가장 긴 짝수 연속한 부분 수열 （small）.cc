#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int arr[50001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    bool flag = false;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
            flag = true;
    }

    int i = 0;
    int j = 0;
    int cnt = arr[0] % 2;
    int ans = 0;

    while (i <= j && j < N)
    {
        if (cnt > K || j + 1 == N)
        {
            if (arr[i] % 2 == 1)
            {
                --cnt;
            }
            ++i;
        }
        else
        {
            ++j;
            if (arr[j] % 2 == 1)
            {
                ++cnt;
            }
        }

        if (cnt <= K)
        {
            int score = j - i + 1 - cnt;
            ans = max(ans, score);
        }
    }

    if (flag == true)
    {
        ans = max(1, ans);
    }
    cout << ans;

    return 0;
}