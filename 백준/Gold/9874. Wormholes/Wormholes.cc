#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define INF 0X7FFFFFFF

using namespace std;
int N;
vector<pair<int, int>> wormholes;
int pair_idx[13];
int next_pos_idx[13];
int answer = 0;

bool FallInLoop()
{
    int start_pos;
    int pos;

    bool is_visited[13];

    for (int i = 0; i < N; ++i)
    {
        fill_n(is_visited, 13, false);

        start_pos = i;
        pos = i;
        
        while (true)
        {   
            //is_visited[pos] = true; 
            pos = next_pos_idx[pos];

            if (pos == -1)
                break;

            if (is_visited[pos])
                return true;

            is_visited[pos] = true;
            pos = pair_idx[pos];
        }
    }

    return false;
}

void print_pairs()
{
    for (int i = 0; i < N; ++i)
    {
        cout << pair_idx[i] << " ";
    }
    cout << "\n";
}

void MakePairs()
{
    int start_pos = 0;
    bool all_pairs = true;

    for (int i = 0; i < N; ++i)
    {
        if (pair_idx[i] != -1)
            continue;

        start_pos = i;
        all_pairs = false;
        break;
    }

    if (all_pairs)
    {
        //print_pairs();
        if (FallInLoop())
        {
            ++answer;
        }
        return;
    }

    for (int i = start_pos + 1; i < N; ++i)
    {
        if (pair_idx[i] != -1)
            continue;

        pair_idx[i] = start_pos;
        pair_idx[start_pos] = i;

        MakePairs();

        pair_idx[i] = -1;
        pair_idx[start_pos] = -1;
    }
}

void Solution()
{
    int curr_x, curr_y;
    int next_x, next_y;
    int min_dist = INF;
    int dist;

    for (int i = 0; i < N; ++i)
    {
        min_dist = INF;

        curr_x = wormholes[i].first;
        curr_y = wormholes[i].second;

        for (int j = 0; j < N; ++j)
        {
            if (i == j)
                continue;

            next_x = wormholes[j].first;
            next_y = wormholes[j].second;

            if (next_y != curr_y)
                continue;

            if (curr_x < next_x)
            {
                dist = next_x - curr_x;
                if (dist < min_dist)
                {
                    min_dist = dist;
                    next_pos_idx[i] = j;
                }
            }
        }
    }

    MakePairs();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int x, y;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        wormholes.push_back({ x,y });
    }

    fill_n(pair_idx, 13, -1);
    fill_n(next_pos_idx, 13, -1);

    Solution();
    
    cout << answer;

    return 0;
}