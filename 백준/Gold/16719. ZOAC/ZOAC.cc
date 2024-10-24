#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool is_visited[101];
string s;

void recursive(int l, int r)
{
    //find smallest 
    int min = 'Z' + 1;
    int index = l;
    int tmp;
    for (int i = l; i <= r; ++i)
    {
        tmp = s[i] - 'A';
        if (tmp < min)
        {
            min = tmp;
            index = i;
        }
    }
    if (min > 'Z')
        return;

    is_visited[index] = true;
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (is_visited[i])
        {
            cnt++;
            cout << s[i];
        }
    }
    cout << "\n";
    if (cnt == s.size())
        return;

    recursive(index + 1, r);
    recursive(l, index - 1);

}
int main()
{
    fill_n(is_visited, 101, false);
    cin >> s;

    recursive(0, s.size() - 1);
    return 0;
}