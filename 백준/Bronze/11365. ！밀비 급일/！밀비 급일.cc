#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (getline(cin,S))
    {
        if (S == "END")
        {
            break;
        }

        reverse(S.begin(), S.end());
        cout << S << "\n";
    }

    return 0;
}