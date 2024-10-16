#include <iostream>
#include <algorithm>

#define N_MAX 101
#define CARD 3

using namespace std;

int N, M;
int n[N_MAX];
int cards[CARD];
bool is_visited[N_MAX];
int ans = 0;

void Input()
{
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
    {
        cin >> n[i];
    }

    fill_n(cards, CARD, 0);
    fill_n(is_visited, N_MAX, false);
}

void Recursive(int k)
{
    if (k== CARD)
    {
        int val = 0;
        for (int i = 0; i < CARD; ++i)
        {
            val += cards[i];
        }
        if (val > ans && val <= M)
        {
            ans = val;
        }
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        if (is_visited[i] == true)
        {
            continue;
        }

        cards[k] = n[i];
        is_visited[i] = true;
        Recursive(k+1);
        is_visited[i] = false;
    }
}

int main()
{
    Input();
    Recursive(0);
    cout << ans;
    return 0;
}