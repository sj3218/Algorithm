#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 6

using namespace std;

int k;
int arr[13];
int answer[13];

void recursive(int idx, int start)
{
    if (idx == SIZE)
    {
        for (int i = 0; i < SIZE; ++i)
        {
            cout << answer[i] << " ";
        }

        cout << "\n";
        return;
    }

    for (int i = start; i < k; ++i)
    {
        answer[idx] = arr[i];
        recursive(idx + 1, i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true)
    {
        cin >> k;
        if (k == 0)
        {
            break;
        }

        fill_n(arr, 13, 0);

        for (int i = 0; i < k; ++i)
        {
            cin >> arr[i];
        }

        recursive(0, 0);

        cout << "\n";
    }
    return 0;
}