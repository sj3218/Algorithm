#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

#define INF 0X7FFFFFFF
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int size = s.size();
    int char_size = 'z' - 'a' + 1;
    vector<bool> mobis(char_size,false);
    char c;
    for (int i = 0; i < size; ++i)
    {
        c = s[i];
        mobis[c - 'A'] = true;
    }

    string answer = "MOBIS";
    bool can_do = true;
    for (int i = 0; i < 5; ++i)
    {
        if (mobis[answer[i]-'A'] == true)
            continue;
        can_do = false;
        break;
    }

    if (can_do)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}