#include <iostream>

using namespace std;
int A, B, C, X, Y;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> A >> B >> C >> X >> Y;

    int ans = A * X + B * Y;
    int sum = 0;

    if (X < Y)
    {
        sum = X * 2 * C;
        sum += (Y - X) * B;

        sum = min(sum, Y * 2 * C);
    }
    else
    {
        sum = Y * 2 * C;
        sum += (X - Y) * A;
        sum = min(sum, X * 2 * C);
    }

    ans = min(ans, sum);
    cout << ans;
    return 0;
}