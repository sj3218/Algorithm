#include <iostream>
#include <cstring>

using namespace std;
int n;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int map[10][10];

void Output()
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << map[i][j] << " ";
        }

        cout << "\n";
    }
}
bool InRange(int x, int y, int& dir)
{
    if (x < 0 || y < 0 || x >= n || y >= n || map[x][y] > 0)
    {
        dir++;
        dir %= 4;
        return false;
    }

    return true;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        memset(map, 0, sizeof(map));
        int start = 1;
        int end;
        cin >> n;
        end = n * n;


        int x = 0;
        int y = 0;
        int dir = 0;
        map[0][0] = start++;

        while (start <= end)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (!InRange(nx, ny, dir))
            {
                continue;
            }

            map[nx][ny] = start;
            x = nx;
            y = ny;
            ++start;
        }
		
        cout<<"#"<<i<<"\n";
        Output();
    }
    return 0;
}