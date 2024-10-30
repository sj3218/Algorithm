
#include <iostream>
#include <string>

using namespace std;

string s;
string key;

int main()
{
    getline(cin, s);
    getline(cin, key);

    int size = s.size();
    int key_size = key.size();
    string ans;
    int index = 0;
    char c;

    for (int i = 0; i < size; ++i)
    {
        index %= key_size;
        if (s[i] == ' ')
        {
            ans += ' ';
            ++index;
            continue;
        }

        c = 'a' + s[i] - key[index++]-1;


        if (c < 'a')
        {
            c = 'z' + 1 - ('a' - c);
        }

        ans += c;
    
    }

    cout << ans;

    return 0;
}