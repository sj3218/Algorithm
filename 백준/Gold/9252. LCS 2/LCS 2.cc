#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

string s1, s2;
int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s1 >> s2;

    int size1 = s1.size();
    int size2 = s2.size();
    int max_cnt = 0;
    for (int i = 1; i <= size1; ++i)
    {
        for (int j = 1; j <= size2; ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[size1][size2] << "\n";
    vector<char> lcs;
    int i = size1;
    int j = size2;
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            lcs.push_back(s1[i - 1]);
            --i;
            --j;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            --i;
        }
        else
            --j;
    }

    for (int i = lcs.size() - 1; i >= 0; --i)
    {
        cout << lcs[i];
    }
    return 0;
}