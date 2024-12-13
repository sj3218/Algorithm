#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
bool is_visited[32001] = { false, };
vector<vector<int>> students;

void Line(int idx)
{
    if (is_visited[idx] == true)
    {
        return;
    }

    int size = students[idx].size();
    for (int i = 0; i < size; ++i)
    {
        Line(students[idx][i]);
    }

    is_visited[idx] = true;
    cout << idx <<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    students.assign(N+1, vector<int>());

    int a, b;
    for (int i = 0; i< M ; ++i)
    {
        cin >> a >> b;
        students[b].push_back(a);
    }

    int size = 0;
    for (int i = 1; i <= N; ++i)
    {
        Line(i);
    }
    return 0;
}