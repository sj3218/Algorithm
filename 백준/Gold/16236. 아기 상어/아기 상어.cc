#include <iostream>
#include <vector>
#include <queue>
using namespace std;

std::vector<std::vector<int>> is_visited;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int n = 0;
vector<vector<int>> map;
int shark_x, shark_y;
int shark_weight = 2;
int eat_count = 0;
int eat_time = 0;

queue<pair<int, int>> q;
vector<pair<int, int>> can_eat_fish;

void input()
{
    cin >> n;
    map.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                map[i][j] = 0;
                shark_x = i;
                shark_y = j;
            }
        }
    }
}

void find_fish()
{
    int cx, cy;
    int min_can_eat = 0;

    while (!q.empty())
    {
        shark_x = q.front().first;
        shark_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            cx = shark_x + dx[i];
            cy = shark_y + dy[i];

            //out of range
            if (cx < 0 || cy < 0 || n <= cx || n <= cy)
                continue;

            if (map[cx][cy] > shark_weight)
                continue;

            if (is_visited[cx][cy] == 0)
            {
                is_visited[cx][cy] = is_visited[shark_x][shark_y] + 1;

                if (map[cx][cy] == 0 || map[cx][cy] == shark_weight)
                {
                    //pass
                    q.push({ cx, cy });
                }
                else
                {
                    //can eat
                    if (min_can_eat == 0 || min_can_eat == is_visited[cx][cy])
                    {
                        min_can_eat = is_visited[cx][cy];
                        can_eat_fish.push_back({ cx, cy });
                    }
                }
            }
        }
    }
}

bool EatFish()
{
    int size = can_eat_fish.size();
    if (size == 0)
    {
        return false;
    }

    shark_x = can_eat_fish[0].first;
    shark_y = can_eat_fish[0].second;
    int cx, cy;

    for (int i = 1; i < size; ++i)
    {
        cx = can_eat_fish[i].first;
        cy = can_eat_fish[i].second;

        if (cx < shark_x) //find upper fish
        {
            shark_x = cx;
            shark_y = cy;
        }
        else if (cx == shark_x)
        {
            //find left one
            if (cy < shark_y)
            {
                shark_x = cx;
                shark_y = cy;
            }
        }
    }

    ++eat_count;
    if (eat_count == shark_weight)
    {
        eat_count = 0;
        shark_weight++;
    }
    can_eat_fish.clear();
    map[shark_x][shark_y] = 0;
    eat_time += is_visited[shark_x][shark_y];
    //std::cout << shark_x << ", " << shark_y << ", eat_time: " << eat_time << std::endl;

    return true;
}

int main()
{
    input();

    while (true)
    {
        is_visited.assign(n, vector<int>(n, 0));
        q.push({ shark_x, shark_y });
        find_fish();

        if (!EatFish())
        {
            cout << eat_time;
            break;
        }
    }
}
