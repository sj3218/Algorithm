#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T, k;
    char c;
    int n;

    cin >> T;

    while (T--)
    {
        cin >> k;
        multiset<int> ms;

        for (int i = 0; i < k; ++i)
        {
            cin >> c >> n;

            if (c == 'D')
            {
                if (ms.empty())
                    continue;
                if (n == 1)
                {
                    ms.erase(prev(ms.end()));
                }
                else
                    ms.erase(ms.begin());
            }
            else
            {
                ms.insert(n);
            }
        }

        if (ms.empty())
            cout << "EMPTY\n";
        else
            cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
    }


    return 0;
}
