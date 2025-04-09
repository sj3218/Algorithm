#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
int space[101][10001];

void compress(int* arr)
{
    vector<int> uni(arr,arr+N);
    sort(uni.begin(), uni.end());
    uni.erase(unique(uni.begin(), uni.end()), uni.end());

    for (int i = 0; i < N; ++i)
    {
        arr[i] = lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> M >> N;
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> space[i][j];
        }

        compress(space[i]);
    }

    int answer = 0;
    for (int i = 0; i < M-1; ++i)
    {
        for (int j = i + 1; j < M; ++j)
        {
            bool is_even = true;
            for (int k = 0; k < N; ++k)
            {
                if (space[i][k] != space[j][k])
                {
                    is_even = false;
                    break;
                }
            }
            if (is_even)
                ++answer;
        }
    }

    cout << answer;
    return 0;
}