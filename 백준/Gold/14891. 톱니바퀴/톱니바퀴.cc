#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

#define WHEELS_COUNT        4
#define WHEEL_STATE         8
#define N                   0
#define S                   1
#define CLOCKWISE           1
#define COUNTER_CLOCKWISE   -1
#define WHEEL_RIGHT_SIDE    2
#define WHEEL_LEFT_SIDE     6

using namespace std;

deque<int> wheels[WHEELS_COUNT+1];
int rotate_cnt;
vector<pair<int, int>> rotate_info;

bool is_visited[WHEELS_COUNT+1];

void RotateWheel(int num, int dir)
{
    if (is_visited[num])
        return;

    is_visited[num] = true;
    int right_side = wheels[num][WHEEL_RIGHT_SIDE];
    int left_side = wheels[num][WHEEL_LEFT_SIDE];
    int side_dir = (dir == COUNTER_CLOCKWISE ? CLOCKWISE : COUNTER_CLOCKWISE);

    if (num != 1)
    {
        //rotate left wheel
        if (left_side != wheels[num - 1][WHEEL_RIGHT_SIDE])
        {
            RotateWheel(num - 1, side_dir);
        }
    }

    if (num != 4)
    {
        //rotate right wheel
        if (right_side != wheels[num + 1][WHEEL_LEFT_SIDE])
        {
            RotateWheel(num + 1, side_dir);
        }
    }

    //rotate center wheel
    if (dir == CLOCKWISE)
    {
        int back = wheels[num].back();
        wheels[num].pop_back();
        wheels[num].push_front(back);
    }
    else
    {
        int front = wheels[num].front();
        wheels[num].pop_front();
        wheels[num].push_back(front);
    }

    is_visited[num] = false;
}

int Solution()
{
    int num, dir;
    for (pair<int, int> order : rotate_info)
    {
        num = order.first;
        dir = order.second;
        RotateWheel(num, dir);
    }

    int sum = 0;
    for (int i = 1; i <= WHEELS_COUNT; ++i)
    {
        if (wheels[i][0] == N)
        {
            continue;
        }

        if (i == 1)
            sum += 1;
        else if (i == 2)
            sum += 2;
        else if (i == 3)
            sum += 4;
        else
            sum += 8;
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    for (int i = 1; i <= WHEELS_COUNT; ++i)
    {
        cin >> s;
        for (int j = 0; j < WHEEL_STATE; ++j)
        {
            wheels[i].push_back(s[j] - '0');
        }
    }

    cin >> rotate_cnt;
    int num, dir;
    for (int i = 0; i < rotate_cnt; ++i)
    {
        cin >> num >> dir;
        rotate_info.push_back({ num,dir });
    }

    cout << Solution();

    return 0;
}