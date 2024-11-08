#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B;
    cin >> A >> B;
    int ans = 0;
    int val = 0;
    int mod;
    for (int i = A; i <= B; ++i)
    {
        val = i;
        while (val)
        {
            mod = val % 10;
            if (mod == 7 || mod == 4)
            {
                val /= 10;
            }
            else
            {
                break;
            }
        }

        if (val == 0)
        {
            ++ans;
        }
    }

    cout << ans;
    return 0;
}