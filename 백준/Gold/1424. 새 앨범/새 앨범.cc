#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int song_cnt;
int length;
int amount;
const int DEVIL_NUM = 13;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> song_cnt >> length >> amount;

    int cnt_by_cd = amount / (length+1);
    if (amount % (length + 1) >= length)
        ++cnt_by_cd;

    if (cnt_by_cd % DEVIL_NUM == 0)
        --cnt_by_cd;

    int answer = song_cnt / cnt_by_cd;
    int left = song_cnt % cnt_by_cd;

    if (answer == 0 && song_cnt % DEVIL_NUM == 0)
    {
        answer += 2;
    }
    else if (left != 0)
    {
        if (left % DEVIL_NUM == 0)
        {
            if ((cnt_by_cd - left) < 2)
                answer += 2;
            else
                ++answer;
        }
        else
            answer++;
    }

    cout << answer;
    return 0;
}