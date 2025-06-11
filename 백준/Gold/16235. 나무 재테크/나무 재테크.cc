#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;
#define BOARD_SIZE      11
#define NUTRIENT        5

int board_size, tree_cnt, taken_time;
int board[BOARD_SIZE][BOARD_SIZE];
int robot[BOARD_SIZE][BOARD_SIZE];
deque<int> trees[BOARD_SIZE][BOARD_SIZE];

int dr[8] = { -1,-1,-1,0,0,1,1,1 };
int dc[8] = { -1,0,1,-1,1,-1,0,1 };

void Input()
{
    fill_n(&board[0][0], BOARD_SIZE * BOARD_SIZE, NUTRIENT);

    cin >> board_size >> tree_cnt >> taken_time;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cin >> robot[i][j];
        }
    }

    int r, c, age;
    for (int i = 0; i < tree_cnt; ++i)
    {
        cin >> r >> c >> age;
        trees[r][c].push_front(age);
    }
}

bool IsValid(int r, int c)
{
    if (r <= 0 || c <= 0 || r > board_size || c > board_size)
        return false;
    return true;
}

//r,c,age
vector<tuple<int,int,int>> Spring()
{
    vector<tuple<int, int, int>> dead_trees;
    int tree_age;
    int cnt;

    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cnt = trees[i][j].size();

            deque<int> temp;
            for (int tree_age : trees[i][j])
            {
                if (tree_age <= board[i][j])
                {
                    board[i][j] -= tree_age;
                    temp.push_back(tree_age + 1);
                }
                else
                {
                    dead_trees.push_back({ i,j,tree_age });
                }
            }

            trees[i][j] = temp;
        }
    }
    return dead_trees;
}

//r,c,age
void Summer(vector<tuple<int,int,int>> dead_trees)
{
    int r, c, age;
    for (tuple<int, int, int> tree : dead_trees)
    {
        tie(r, c, age) = tree;
        
        board[r][c] += (age / 2);
    }
}

void Fall()
{
    int nr, nc, age;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            for (int tree_age : trees[i][j])
            {
                if (tree_age % 5 != 0)
                    continue;

                for (int k = 0; k < 8; ++k)
                {
                    nr = i + dr[k];
                    nc = j + dc[k];
                    if (!IsValid(nr, nc))
                        continue;
                    if (nr == i && nc == j)
                        continue;

                    trees[nr][nc].push_front(1);
                }
            }
        }
    }
}

void Winter()
{
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            board[i][j] += robot[i][j];
        }
    }
}

void print_tree_cnt()
{
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            cout << trees[i][j].size() << " ";
        }
        cout << "\n";
    }

    cout << "\n";
}
int Solution()
{
    while (taken_time--)
    {
        Summer(Spring());
        Fall();
        Winter();
        //print_tree_cnt();
    }

    int total_tree_cnt = 0;
    for (int i = 1; i <= board_size; ++i)
    {
        for (int j = 1; j <= board_size; ++j)
        {
            total_tree_cnt += trees[i][j].size();
        }
    }
    return total_tree_cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    cout << Solution();

    return 0;
}