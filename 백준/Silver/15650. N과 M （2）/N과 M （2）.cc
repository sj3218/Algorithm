#include <iostream>
#include <algorithm>
#define MAX 9

using namespace std;

int N, M;
int arr[MAX];
int is_visited[MAX];

void Input()
{
    cin >> N >> M;
    fill_n(arr, MAX, 0);
    fill_n(is_visited, MAX, false);
}

void Recursive(int k,int val)
{
    if (k == M)
    {
        for (int i = 0; i < M; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = val; i <= N; ++i)
    {
        if (is_visited[i] == true)
        {
            continue;
        }

        arr[k] = i;
        is_visited[i] = true;
        Recursive(k+1, i+1);
        is_visited[i] = false;
    }
}

int main()
{
    Input();

    Recursive(0,1);
    return 0;
}