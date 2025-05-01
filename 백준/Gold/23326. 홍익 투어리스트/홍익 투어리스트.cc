#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <tuple>

using namespace std;

int N, Q;
set<int> tourist_spots;
int pos = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> Q;
    
    int x;
    for (int i = 1; i <= N; ++i)
    {
        cin >> x;
        if(x == 1)
            tourist_spots.insert(i);
    }

    for (int i = 0; i < Q; ++i)
    {
        cin >> x;
        if (x == 1)
        {
            int spot;
            cin >> spot;
            set<int>::iterator it = tourist_spots.find(spot);
            if (it == tourist_spots.end())
            {
                tourist_spots.insert(spot);
            }
            else
            {
                tourist_spots.erase(spot);
            }
        }
        else if (x == 2)
        {
            int dis;
            cin >> dis;

            pos = (pos + dis - 1) % N + 1;
        }
        else
        {
            if (tourist_spots.empty())
            {
                cout << -1 << "\n";
                continue;
            }

            set<int>::iterator it = tourist_spots.lower_bound(pos);
            if (it == tourist_spots.end())
            {
                cout << N - pos + *tourist_spots.begin() << "\n";
            }
            else
            {
                cout << *it - pos << "\n";
            }
        }
    }

    return 0;
}
