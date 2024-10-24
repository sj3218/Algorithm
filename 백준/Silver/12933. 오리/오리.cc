#include <iostream>
#include <string>
#include <algorithm>
#define QUACK_SIZE 5

using namespace std;

bool is_visited[2501];
string quack = "quack";

int main()
{
    string s;
    fill_n(is_visited, 2501, false);

    cin >> s;

    if (s.size() < QUACK_SIZE)
    {
        cout << "-1";
        return 0;
    }

    int ans = 0;
    int count = 0;
    int size = s.size();

    while (true)
    {
        int index = 0;
        int tmpCnt = 0;
        if (count == size)
            break;

        for (int i = 0; i < size; ++i)
        {
            if (is_visited[i])
                continue;

            if (s[i] != quack[index])
                continue;

            index++;
            index = index % QUACK_SIZE;
            is_visited[i] = true;
            tmpCnt++;
        }

        if (tmpCnt == 0 || index > 0)
        {
            cout << "-1";
            return 0;
        }

        ++ans;
        count += tmpCnt;
    }

    cout << ans;
    return 0;
}