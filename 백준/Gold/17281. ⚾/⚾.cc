#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;

const int MAX_PLAYER_CNT = 9;
const int MAX_OUT_CNT = 3;

int N;
bool base[5];
int info[51][MAX_PLAYER_CNT + 1];
int order[MAX_PLAYER_CNT + 1];
bool is_visited[MAX_PLAYER_CNT + 1];
int answer = 0;

void Input()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= MAX_PLAYER_CNT; ++j)
        {
            cin >> info[i][j];
        }
    }
}

int CalculateEarnedScore(int base_hit)
{
    int score = 0;
    base[0] = true;
    for (int i = 4; i >= 0; --i)
    {
        if (!base[i])
            continue;
        
        base[i] = false;

        if (i + base_hit >= 4)
        {
            ++score;
        }
        else
        {
            base[i + base_hit] = true;
        }
    }

    return score;
}

int FindScore()
{
    int curr_player_idx = 1;
    int curr_player;
    int inning_idx = 1;
    int out_cnt = 0;
    int score = 0;
    fill_n(base, 5, false);

    //simulate each inning
    while (true)
    {
        curr_player = order[curr_player_idx];

        if (inning_idx > N)
            break;

        if (info[inning_idx][curr_player] == 0)
        {
            ++out_cnt;
            if (out_cnt == MAX_OUT_CNT)
            {
                ++inning_idx;
                out_cnt = 0;
                fill_n(base, 5, false);
            }
        }
        else
        {
            score += CalculateEarnedScore(info[inning_idx][curr_player]);
        }

        if (++curr_player_idx > MAX_PLAYER_CNT)
        {
            curr_player_idx = 1;
        }
    }
    return score;
}

void FindOrder(int idx)
{
    if (idx > MAX_PLAYER_CNT)
    {
        //simulation
        answer = max(answer, FindScore());

        return;
    }
    if (idx == 4)
    {
        //skip at this idx because 1st player has already gotten this seat.
        FindOrder(idx + 1);
        return;
    }

    //find order using dfs
    for (int i = 2; i <= MAX_PLAYER_CNT; ++i)
    {
        if (is_visited[i])
            continue;

        is_visited[i] = true;
        order[idx] = i;
        FindOrder(idx + 1);
        is_visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    Input();

    //set first player as 4rd hitter
    order[4] = 1;
    is_visited[1] = true;

    FindOrder(1);
    cout << answer;

    return 0;
}