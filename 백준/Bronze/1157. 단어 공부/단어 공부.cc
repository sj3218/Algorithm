#include <iostream>
#include <algorithm>
#include <string>
#define ALPHABET 26

using namespace std;

string s;
int dp[ALPHABET];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s;

    int size = s.size();
    int idx = 0;

    for (int i = 0; i < size; ++i)
    {
        char c = s[i];

        if (c >= 'A' && c <= 'Z')
        {
            idx = c - 'A';
        }
        else if (c >= 'a' && c <= 'z')
        {
            idx = c - 'a';
        }
        else
        {
            continue;
        }

        ++dp[idx];
    }

    int answer = 0;
    bool is_existed = false;

    for (int i = 0; i < ALPHABET; ++i)
    {
        if (answer == dp[i])
        {
            if (answer == 0)
                continue;
            is_existed = true;
            continue;
        }
        else if (answer < dp[i])
        {
            is_existed = false;
            answer = dp[i];
            idx = i;
        }
    }

    if (is_existed)
        cout << "?";
    else
    {
        char c = 'A' + idx;
        cout << c;
    }

    return 0;
}