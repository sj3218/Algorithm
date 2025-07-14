#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int N;
int numbers[2001];
int M;
int s, e;
bool dp[2001][2001];

void palindrome()
{
    int j;
    for (int i = 1; i < N; ++i)
    {
        dp[i][i + 1] = numbers[i] == numbers[i + 1];
    }

    for (int len = 2; len <= N; ++len)
    {
        for (int i = 1; i + len <= N; ++i)
        {
            j = i + len;
            dp[i][j] = (numbers[i] == numbers[j]) && dp[i + 1][j - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> numbers[i];
        dp[i][i] = true;
    }

    palindrome();

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> s >> e;
        if (dp[s][e])
            cout << "1\n";
        else
            cout << "0\n";
    }

    return 0;
}