#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

string original;
string bomb;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> original >> bomb;

    string answer;
    size_t bomb_size = bomb.size(); 
    for (char c : original)
    {
        answer += c;
        
        if (answer.size() >= bomb_size)
        {
            if (answer.substr(answer.size() - bomb_size, bomb_size) == bomb)
            {
                answer.erase(answer.size() - bomb_size);
            }
        }
    }

    if (answer.size() == 0)
        cout << "FRULA";
    else
        cout << answer;

    return 0;
}