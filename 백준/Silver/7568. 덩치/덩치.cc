#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
vector<pair<int,int>> informations;
int ranking[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    cin >> N;
    informations = vector<pair<int,int>>(N + 1);
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        informations[i] = { x,y };
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = i+1; j < N; ++j)
        {
            if (informations[i].first > informations[j].first)
            {
                if (informations[i].second > informations[j].second)
                    ranking[j]++;
            }
            else if (informations[i].first < informations[j].first)
            {
                if (informations[i].second < informations[j].second)
                    ranking[i]++;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        cout << ranking[i] + 1 << " ";
    }

    return 0;
}