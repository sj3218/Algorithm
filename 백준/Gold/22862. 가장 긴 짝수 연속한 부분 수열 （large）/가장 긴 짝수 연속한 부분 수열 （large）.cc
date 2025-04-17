#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
int arr[1000001];

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
    int answer = 0;
    int length = 0;
    int cnt_k = 0;

    while (start <= end && end < N)
    {
        if (arr[end] % 2 == 0)
        {
            ++length;
            ++end;
            answer = max(answer, length);
        }
        else
        {
            if (start == end)
            {
                ++start;
                ++end;
                continue;
            }

            if (cnt_k < K)
            {
                ++cnt_k;
                ++end;
            }
            else
            {
                if (arr[start] % 2 == 0)
                {
                    ++start;
                    --length;
                }
                else
                {
                    ++start;
                    --cnt_k;
                }
            }

        }
    }

    cout << answer;
    return 0;
}