#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define BOARD_SIZE  51
#define CITY_SIZE   2605
#define INF         0X7FFFFFFF
#define HOME        1
#define STORE     2

using namespace std;

int board_size, cnt_selected_stores;
int board[BOARD_SIZE][BOARD_SIZE];

vector<pair<int, int>> store_pos;
vector<pair<int, int>> home_pos;
int cnt_store;
int cnt_home;

vector<vector<int>> chicken_distance;
bool is_visited[CITY_SIZE];
int answer = INF;

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > board_size || y > board_size)
        return false;
    return true;
}

int CalcDistance(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

void FindChickenDistance()
{
    int idx = 0;
    int dist;
    for (pair<int, int> home : home_pos)
    {
        int store_idx = 0;
        for (pair<int, int> store : store_pos)
        {
            dist = CalcDistance(home.first, home.second, store.first, store.second);
            chicken_distance[idx][store_idx++] = dist;
        }
        ++idx;
    }
}

int CalcCityChickenDistance()
{
    int sum = 0;

    for (int i = 0; i < cnt_home; ++i)
    {
        int dist = INF;
        for (int j = 0; j < cnt_store; ++j)
        {
            if (is_visited[j] == false)
                continue;

            dist = min(dist, chicken_distance[i][j]);
        }
        sum += dist;
    }
    return sum;
}

void dfs(int count, int start)
{
    if (count == cnt_selected_stores)
    {
        int dist = CalcCityChickenDistance();
        answer = min(dist, answer);
    }

    for (int i = start; i < cnt_store; ++i)
    {
        if (is_visited[i])
            continue;

        is_visited[i] = true;
        dfs(count + 1, i + 1);
        is_visited[i] = false;
    }
}

void Solution()
{
    //find all of the distance of chicken store
    FindChickenDistance();

    //select the chicken store and then calculate the city chicken distance
    dfs(0, 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> board_size >> cnt_selected_stores;

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == HOME)
            {
                home_pos.push_back({ i,j });
            }
            else if (board[i][j] == STORE)
            {
                store_pos.push_back({ i,j });
            }
        }
    }

    cnt_store = store_pos.size();
    cnt_home = home_pos.size();
    chicken_distance.assign(cnt_home, vector<int>(cnt_store));

    Solution();
    cout << answer;

    return 0;
}