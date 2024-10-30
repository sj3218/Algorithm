#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define DIVIDE 10007

int N, M, H;
vector<vector<int>> arr;
vector<vector<int>> dp;

void Input()
{
    cin >> N >> M >> H;
    arr.assign(N, vector<int>());
    dp.assign(N + 1, vector<int>(H + 1, 0));
    cin.ignore();

    string s;
    for (int i = 0; i < N; ++i)
    {
        getline(cin, s, '\n');

        for (int j = 0; j < s.size(); ++j)
        {
            if (s[j] == ' ' || j == 0)
            {
                arr[i].push_back(stoi(&s[j]));
            }
        }

        dp[i][0] = 1;
    }
}
int main()
{
    Input();

    for (int i = 1; i <= N; ++i)
    {
        int size = arr[i - 1].size();

        for (int j = 1; j <= H; ++j)
        {
            for (int k = 0; k < size; ++k)
            {
                int height = arr[i-1][k];
                if (height <= j)
                {
                    dp[i][j] += dp[i - 1][j - height];
                    dp[i][j] %= DIVIDE;
                }
            }
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= DIVIDE;
        }
    }

    cout << dp[N][H];
    return 0;
}