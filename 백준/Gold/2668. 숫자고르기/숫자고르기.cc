#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int N;
int nums[101];
bool is_visited[101];
vector<int> in_set;
vector<int> in_idx;

bool HasSame()
{
    int size = in_set.size();
    if (size == in_idx.size())
    {
        for (int i = 0; i < size; ++i)
        {
            if (find(in_set.begin(), in_set.end(), in_idx[i]) == in_set.end())
                return false;
        }
    }
    else
        return false;

    return true;
}

bool dfs(int x)
{
    int set_x = nums[x];

    if (is_visited[set_x])
    {
        if (find(in_set.begin(), in_set.end(), set_x) != in_set.end())
        {
            if(HasSame())
                return true;
        }
        return false;
    }
    
    is_visited[set_x] = true;
    in_idx.push_back(x);
    in_set.push_back(set_x);

    if (dfs(set_x))
        return true;
    is_visited[set_x] = false;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> nums[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        in_set.clear();
        in_idx.clear();
        dfs(i);
    }

    int cnt = 0;
    vector<int> set_num;
    for (int i = 1; i <= N; ++i)
    {
        if (is_visited[i])
        {
            ++cnt;
            set_num.push_back(i);
        }
    }
    cout << cnt <<"\n";
    for (int i : set_num)
    {
        cout << i << "\n";
    }
    return 0;
}