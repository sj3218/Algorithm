#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S, K;
    cin >> S >> K;

    int s_length = S.length();
    string ss;

    for (int i = 0; i < s_length; ++i)
    {
        if ('0' <= S[i] && S[i] <= '9')
        {
            continue;
        }

        ss += S[i];
    }

    if (ss.find(K) == string::npos)
    {
        cout << "0";
    }
    else
    {
        cout << "1";
    }
    return 0;
}