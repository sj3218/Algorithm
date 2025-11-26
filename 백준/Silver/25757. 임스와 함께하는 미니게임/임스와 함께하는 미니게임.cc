#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int N;
char game;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> game;
    int cnt = 1;
    int total_game_cnt = 0;
    map<string, bool>has_name;
    string name;

    for (int i = 0; i < N; ++i)
    {
        cin >> name;
        if (has_name.find(name) != has_name.end())
        {
            continue;
        }

        has_name[name] = true;
        ++cnt;
        if (game == 'Y' && cnt == 2)
        {
            cnt = 1;
            total_game_cnt++;
        }
        else if (game == 'F' && cnt == 3)
        {
            cnt = 1;
            total_game_cnt++;
        }
        else if(game == 'O' && cnt ==4)
        {
            cnt = 1;
            total_game_cnt++;
        }
    }

    cout << total_game_cnt;

    return 0;
}