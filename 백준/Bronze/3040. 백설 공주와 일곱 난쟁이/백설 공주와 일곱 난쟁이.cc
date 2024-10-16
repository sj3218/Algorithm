#include <iostream>
#define CNT 9
using namespace std;

int dwarf[CNT];
bool is_visited[CNT];
int real_dwarf[7];

void Input()
{
    for (int i = 0; i < CNT; ++i)
    {
        cin >> dwarf[i];
        is_visited[i] = false;
    }
}

bool Recursive(int k, int sum)
{
    if (k == 7)
    {
        if (sum == 100)
        {
            return true;
        }
        return false;
    }

    for (int i = 0; i < CNT; ++i)
    {
        if (is_visited[i])
            continue;

        is_visited[i] = true;
        real_dwarf[k] = dwarf[i];
        if (Recursive(k + 1, dwarf[i] + sum))
            return true;

        is_visited[i] = false;
    }
    return false;
}

int main()
{
    Input();

    if (Recursive(0,0))
    {
        for (int i = 0; i < 7; ++i)
        {
            cout << real_dwarf[i] << endl;
        }
    }
    return 0;
}