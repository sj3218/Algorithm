#include<iostream>

#define MAX 100
using namespace std;

int grid[MAX][MAX];
int goal_x, goal_y;

bool InRange(int x, int y)
{
    if (x < 0 || y < 0 || x >= MAX || y >= MAX)
        return false;
    return true;
}

void Input()
{
    for (int i = 0; i < MAX; ++i)
    {
        for (int j = 0; j < MAX; ++j)
        {
            cin >> grid[i][j];

            if (grid[i][j]==2)
            {
                goal_x = i;
                goal_y = j;
            }
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

   while(cin>>T)
    {
        Input();

        int x = goal_x;
        int y = goal_y;
        
        while (x > 0)
        {
            if (InRange(x, y + 1) && grid[x][y+1] == 1)
            {
                grid[x][y] = 2;
                ++y;
            }
            else if (InRange(x, y - 1) && grid[x][y-1] == 1)
            {
                grid[x][y] = 2;
                --y;
            }
            else
            {
                grid[x][y] = 2;
                --x;
            }
        }
        cout << "#" << T << " " << y << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}