#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define ALPHABET 'z' - 'a' + 1
int is_visited[ALPHABET];

void dfs(int index, string s)
{
    if (index == s.size())
    {
        cout << s << "\n";
        return;
    }

    for (int i = 0; i < ALPHABET; ++i)
    {
        if (is_visited[i] > 0)
        {
            --is_visited[i];

            s[index] = 'a' + i;
            dfs(index + 1, s);

            ++is_visited[i];
        }
    }
}

int main()
{
    int N;
    
    string s;

    cin >> N;

    for (int words = 0; words < N; ++words)
    {
        fill_n(is_visited, ALPHABET, 0);
        cin >> s;
        int size = s.size();

        for (int i = 0; i < size; ++i)
        {
            is_visited[s[i] - 'a']++;
        }

        dfs(0, s);

    }
    return 0;
}