#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char S[1000001];
char P[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S;
    cin >> P;

    char* ptr = strstr(S, P);

    if (ptr != nullptr)
    {
        cout << "1";
    }
    else
        cout << "0";

    return 0;
}