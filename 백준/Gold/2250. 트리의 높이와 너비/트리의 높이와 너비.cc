#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define INF 0X7FFFFFF

using namespace std;

int N;
int c, l, r;
vector<vector<int>> tree(10001);
vector<pair<int, int>> index_information(10001); //width, level 
pair<int, int> level_values[10001]; // smallest, largest
bool is_visited[10001]; //find root
int root;

void dfs(int root, int& width, int level)
{
    if (tree[root][0] != -1)
    {
        dfs(tree[root][0], width, level + 1);
    }

    if (level_values[level].first > width)
        level_values[level].first = width;
    if (level_values[level].second < width)
        level_values[level].second = width;

    index_information[root].first = width;
    index_information[root].second = level;
    ++width;

    if (tree[root][1] != -1)
    {
        dfs(tree[root][1], width, level + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    fill_n(level_values, 10001, pair<int, int>(INF, 0));
    
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> c >> l >> r;
        tree[c].push_back(l);
        tree[c].push_back(r);
        is_visited[l] = true;
        is_visited[r] = true;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (is_visited[i] == false)
        {
            root = i;
            break;
        }
    }
    int width = 1;

    dfs(root, width, 1);
    
    int x, y;
    int level = 1;
    int answer = 0;
    int answer_level = 0;
    while (true)
    {
        x = level_values[level].first;
        y = level_values[level].second;

        if (x == INF && y == 0)
            break;

        if (answer < y - x + 1)
        {
            answer = y - x + 1;
            answer_level = level;
        }

        ++level;
    }

    cout << answer_level << " " << answer;

    return 0;
}