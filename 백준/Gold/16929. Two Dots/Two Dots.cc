#include <iostream>
#include <vector>

int n;
int m;
std::vector<std::vector<char>> map;
std::vector<std::vector<bool>> is_visited;

std::vector<int> dx{ 0,0,1,-1 };
std::vector<int> dy{ 1,-1,0,0 };

int start_x, start_y;

void input()
{
    std::cin >> n >> m;

    is_visited.assign(n, std::vector<bool>(m, false));//assign "false" as much as map

    char c;
    for (int i = 0; i < n; ++i)
    {
        std::vector<char> row;
        for (int j = 0; j < m; ++j)
        {
            std::cin >> c;
            row.push_back(c);
        }
        map.push_back(row);
    }
}

bool dfs(int x, int y, int depth)
{
    if (depth >= 4 && start_x == x && start_y == y)
    {
        is_visited[x][y] = false;
        return true;
    }

    char curr_c = map[x][y];
    for (int i = 0; i < 4; ++i)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (new_x < 0 || n <= new_x || new_y < 0 || m <= new_y)
        {
            continue;
        }

        if (map[new_x][new_y] == curr_c && is_visited[new_x][new_y] == false)
        {
            is_visited[new_x][new_y] = true;

            if (dfs(new_x, new_y, depth + 1))
            {
                is_visited[new_x][new_y] = false;
                return true;
            }

            is_visited[new_x][new_y] = false;
        }
    }

    return false;
}

int main()
{
    input();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            start_x = i;
            start_y = j;

            if (dfs(i, j, 1))
            {
                std::cout << "Yes";
                return 0;
            }
        }
    }

    std::cout << "No";
    return 0;
}