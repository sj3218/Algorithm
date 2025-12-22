#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;

int N;
int coordinate[500001];

void Input()
{
    cin >> N;
    int x, y;
    for (int i = 0; i < N; ++i)
    {
        cin >> x >> y;
        coordinate[i] = y;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();

    stack<int> height;
    height.push(0);

    int curr_height;
    int cnt = 0;
    int top_height;

    for (int i = 0; i < N; ++i)
    {
        curr_height = coordinate[i];

        while (height.top() > curr_height)
        {
            height.pop();
        }
        
        if (height.top() < curr_height)
        {
            ++cnt;
            height.push(curr_height);
        }
    }

    cout << cnt;
    return 0;
}