#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int cnt_commands;
    string command;
    cin >> cnt_commands;
    queue<int> q;

    int value;
    for (int i = 0; i < cnt_commands; ++i)
    {
        cin >> command;

        if (command == "push")
        {
            cin >> value;
            q.push(value);
        }
        else if (command == "front")
        {
            if (!q.empty())
                cout << q.front() << "\n";
            else
                cout << "-1\n";
        }
        else if (command == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
                cout << "-1\n";
        }
        else if (command == "empty")
        {
            if (q.empty())
                cout << "1\n";
            else
                cout << "0\n";
        }
        else if (command == "size")
        {
            cout << q.size() << "\n";
        }
        else if(command == "back")
        {
            if (!q.empty())
                cout << q.back() << "\n";
            else
                cout << "-1\n";
        }
    }

    return 0;
}