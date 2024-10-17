#include <iostream>

using namespace std;

int N, M;
int arr[100001];
int sum[100001];
int s, e;

void Input()
{
    cin >> N >> M;

    cin >> arr[0];
    sum[0] = arr[0];

    for (int i = 1; i < N; ++i)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    Input();

    for (int i = 0; i < M; ++i)
    {

        cin >> s >> e;
        int ans = sum[e - 1];
        if (s != 1)
        {
            ans -= sum[s-2];
        }

        cout << ans << "\n";;
    }
    return 0;
}