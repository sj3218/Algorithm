#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string S, T;
int ans = 0;

void recursive(string s)
{
    if (S == s)
    {
        ans = 1;
        return;
    }

    if (s.size() <= S.size())
    {
        return;
    }

    if (s[s.size() - 1] == 'A')
    {
        string tmp = s;
        tmp.erase(tmp.end() - 1);
        recursive(tmp);
    }
    
    if(s[0] == 'B')
    {
        string tmp = s;
        tmp.erase(tmp.begin());
        reverse(tmp.begin(), tmp.end());
        recursive(tmp);
    }
}

int main()
{
    cin >> S >> T;

    recursive(T);

    cout << ans;

    return 0;
}