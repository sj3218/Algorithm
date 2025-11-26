#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool IncludeVowel(string s)
{
    int size = s.size();
    char c;
    for (int i = 0; i < size; ++i)
    {
        c = s[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            return true;
        }
    }
    return false;
}

bool IsVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    return false;
}
bool HasContinuousVowel(string s)
{
    int size = s.size();
    bool is_vowel = false;
    char pre_c = s[0];
    if (IsVowel(pre_c))
        is_vowel = true;
    int cnt = 1;
    bool curr_is_vowel;
    for (int i = 1; i < size; ++i)
    {
        curr_is_vowel = IsVowel(s[i]);

        if (curr_is_vowel && is_vowel)
            ++cnt;
        else if (!curr_is_vowel && !is_vowel)
            ++cnt;
        else
        {
            is_vowel = curr_is_vowel;
            cnt = 1;
        }
        if (cnt == 3)
            return true;
    }
    return false;
}

bool HasContinuous(string s)
{
    int size = s.size();
    char pre_c = s[0];
    int cnt = 1;
    for (int i = 1; i < size; ++i)
    {
        if (pre_c == s[i])
            ++cnt;
        else
        {
            pre_c = s[i];
            cnt = 1;
        }

        if (cnt == 2 && (pre_c != 'e' && pre_c != 'o'))
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    while (true)
    {
        cin >> s;
        if (s == "end")
            break;
        if (IncludeVowel(s) && !HasContinuous(s) && !HasContinuousVowel(s))
        {
            cout << "<" << s << "> is acceptable.\n";
        }
        else
        {
            cout << "<" << s << "> is not acceptable.\n";
        }
    }

    return 0;
}