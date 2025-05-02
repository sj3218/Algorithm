#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

int N;
string command;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    set<int> all;
    set<int> S;

    for (int i = 1; i <= 20; ++i)
    {
        all.insert(i);
    }

    cin >> N;

    int x;
    for (int i = 0; i < N; ++i)
    {
        cin >> command;
        
        if (command == "add")
        {
            cin >> x;
            S.insert(x);
        }
        else if (command == "remove")
        {
            cin >> x;
            if (S.find(x) != S.end())
            {
                S.erase(x);
            }
        }
        else if (command == "check")
        {
            cin >> x;
            if (S.find(x) != S.end())
            {
                cout << "1\n";
            }
            else
                cout << "0\n";
        }
        else if (command == "toggle")
        {
            cin >> x;
            if (S.find(x) == S.end())
                S.insert(x);
            else
                S.erase(x);
        }
        else if (command == "all")
        {
            S = all;
        }
        else
        {
            S.clear();
        }
    }
    return 0;
}
