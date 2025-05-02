#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <fstream>

using namespace std;

int N, M;
string name;
set<string> cannot_listen;
set<string> answer_list;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> name;
        cannot_listen.insert(name);
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> name;
        if (cannot_listen.find(name) != cannot_listen.end())
            answer_list.insert(name);
    }

    cout << answer_list.size() <<"\n";
    for (string n : answer_list)
    {
        cout << n << "\n";
    }
    return 0;
}
