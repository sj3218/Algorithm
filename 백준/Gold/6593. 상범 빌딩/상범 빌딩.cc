#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
#include <string>

using namespace std;

int num_building_cnt;
int Row, Col;
bool building[31][31][31];
int is_visited[31][31][31];
tuple<int, int, int> start_pos;//z,y,x
tuple<int, int, int> end_pos;

int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = { 1,-1,0,0,0,0 };

bool IsValid(int z, int y, int x)
{
    if (z <= 0 || z > num_building_cnt || y <= 0 || y > Row || x <= 0 || x > Col)
        return false;
    return true;
}

bool bfs()
{
    queue<tuple<int, int, int>> q;
    q.push(start_pos);
    is_visited[get<0>(start_pos)][get<1>(start_pos)][get<2>(start_pos)] = 0;

    int cx, cy, cz;
    int nx, ny, nz;
    int curr_time;

    while (!q.empty())
    {
        cz = get<0>(q.front());
        cy = get<1>(q.front());
        cx = get<2>(q.front());
        curr_time = is_visited[cz][cy][cx];

        if (q.front() == end_pos)
            return true;

        q.pop();

        for (int i = 0; i < 6; ++i)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];
            nz = cz + dz[i];

            if (!IsValid(nz, ny, nx))
                continue;

            if (building[nz][ny][nx] == false)
                continue;

            if (is_visited[nz][ny][nx] != -1)
                continue;

            is_visited[nz][ny][nx] = curr_time + 1;
            q.push({ nz, ny, nx });
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string line;
    while (true)
    {
        cin >> num_building_cnt >> Row >> Col;
        if (num_building_cnt == 0 && Row == 0 && Col == 0)
            break;

        fill_n(&building[0][0][0], 31 * 31 * 31, 0);
        fill_n(&is_visited[0][0][0], 31 * 31 * 31, -1);

        for (int i = 1; i <= num_building_cnt; ++i)
        {
            for (int j = 1; j <= Row; ++j)
            {
                cin >> line;
                for (int k = 1; k <= Col; ++k)
                {
                    if (line[k - 1] == '#')
                    {
                        building[i][j][k] = false;
                        continue;
                    }
                    else if (line[k - 1] == 'S')
                    {
                        start_pos = { i, j, k };
                    }
                    else if (line[k - 1] == 'E')
                    {
                        end_pos = { i,j,k };
                    }

                    building[i][j][k] = true;
                }
            }
        }

        if (bfs())
        {
            cout << "Escaped in " << is_visited[get<0>(end_pos)][get<1>(end_pos)][get<2>(end_pos)] << " minute(s).\n";
        }
        else
        {
            cout << "Trapped!\n";
        }
    }

    return 0;
}
