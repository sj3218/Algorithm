#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <tuple>

using namespace std;

int N;
int P, L, G;
int M;
string command;

set<int> problemByGL[101][101]; // group -> level -> problem
set<int> problemByLevel[101];   //level -> problem
pair<int, int> problems[100001]; // group, level

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> P >> L >> G;
        problems[P] = { G,L };
        problemByLevel[L].insert(P);
        problemByGL[G][L].insert(P);
    }

    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        cin >> command;
        if (command == "add")
        {
            cin >> P >> L >> G;
            problems[P] = { G,L };
            problemByLevel[L].insert(P);
            problemByGL[G][L].insert(P);
        }
        else if (command == "solved")
        {
            cin >> P;
            problemByLevel[problems[P].second].erase(P);
            problemByGL[problems[P].first][problems[P].second].erase(P);
        }
        else if (command == "recommend")
        {
            cin >> G >> L;
            if (L == 1)
            {
                for (int i = 100; i >= 0; --i)
                {
                    if (problemByGL[G][i].empty())
                        continue;
                    cout << *prev(problemByGL[G][i].end()) << "\n";
                    break;
                }
            }
            else
            {
                for (int i = 0; i <= 100; ++i)
                {
                    if (problemByGL[G][i].empty())
                        continue;
                    cout << *problemByGL[G][i].begin() << "\n";
                    break;
                }
            }
        }
        else if (command == "recommend2")
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
        else
        {
            int x;
            cin >> x >> L;
            int answer = -1;
            if (x == 1)
            {
                for (int i = L; i <= 100; ++i)
                {
                    if (problemByLevel[i].empty())
                        continue;
                    answer = *problemByLevel[i].begin();
                    break;
                }
            }
            else
            {
                for (int i = L - 1; i >= 0; --i)
                {
                    if (problemByLevel[i].empty())
                        continue;
                    answer = *prev(problemByLevel[i].end());
                    break;
                }
            }
            cout << answer << "\n";
        }
    }
    return 0;
}
