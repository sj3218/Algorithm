#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
int dp_zero[41];
int dp_one[41];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    dp_zero[0] = 1;
    dp_zero[1] = 0;
    dp_one[0] = 0;
    dp_one[1] = 1;

    for (int i = 2; i <= 40; ++i)
    {
        dp_one[i] = dp_one[i - 1] + dp_one[i - 2];
        dp_zero[i] = dp_zero[i - 1] + dp_zero[i - 2];
    }

    cin >> T;

    while (T-- > 0)
    {
        cin >> N;
        cout << dp_zero[N] << " " << dp_one[N] <<"\n";
    }

    return 0;
}