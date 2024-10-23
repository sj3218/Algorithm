#include <iostream>
using namespace std;

int T;
int N, M;

int main()
{
    cin >> T;

    for (int test = 0; test < T; ++test)
    {
        cin >> N >> M;
        int ans = 1;
        int tmp = 1;

        for (int i = M; i > M - N; --i)
        {
            ans *= i;
            ans /= tmp++;
        }

        cout << ans << "\n";
    }


    return 0;
}