#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <tuple>

using namespace std;

int N;
int P, L;
int M;
string command;

set<int> problemByLevel[101];
int problemLevel[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> P >> L;
        problemLevel[P] = L;
        problemByLevel[L].insert(P);
    }

    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        cin >> command;
        if (command == "add")
        {
            cin >> P >> L;
            problemLevel[P] = L;
            problemByLevel[L].insert(P);
        }
        else if (command == "solved")
        {
            cin >> P;
            problemByLevel[problemLevel[P]].erase(P);
        }
        else
        {
            cin >> L;
            if (L == 1)
            {
                for (int i = 100; i >= 0; --i)
                {
                    if (problemByLevel[i].empty())
                        continue;
                    cout << *prev(problemByLevel[i].end()) << "\n";
                    break;
                }
            }
            else
            {
                for (int i = 0; i <= 100; ++i)
                {
                    if (problemByLevel[i].empty())
                        continue;
                    cout << *problemByLevel[i].begin() << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}
