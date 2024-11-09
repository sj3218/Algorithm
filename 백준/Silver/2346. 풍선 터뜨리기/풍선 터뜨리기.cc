#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<pair<int, int>> v;

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> arr[i];
        v.push_back({ i, arr[i] });
    }

    int index = 0;
    int move, ballon;
    while (v.size() > 0)
    {
        ballon = v[index].first;
        move = v[index].second;
        cout << ballon << " ";

        v.erase(v.begin() + index);
        if (v.size() == 0)
            break;

        if (move > 0)
        {
            --index;
            index = (index + move) % v.size();
        }
        else
        {
            move = abs(move) % v.size();
            index = (index - move + v.size()) % v.size();
        }

    }


    return 0;
}