#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <map>

#define INF 0X7FFFFFFF
using namespace std;

string s1, s2;
int dp[1001][1001]; //dp[i][j] = s1의 i까지, s2의 j까지 비교 -> 최대 길이

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> s1 >> s2;

    int size1 = s1.size();
    int size2 = s2.size();

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

    cout << dp[size1][size2];
    return 0;
}