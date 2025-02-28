#include <iostream>
#include <string>
using namespace std;

string S;
bool dp[51][51][51][3][3];
string ans;
int cnt_a = 0;
int cnt_b = 0;
int cnt_c = 0;

bool dfs(int a, int b, int c, int p, int pp)
{
    if (a == cnt_a && b == cnt_b && c == cnt_c)
        return true;

    if (p != -1 && pp != -1)
    {
        if (dp[a][b][c][p][pp] == true)
            return false;

        dp[a][b][c][p][pp] = true;
    }

    if (a < cnt_a)
    {
        ans += 'A';
        if (dfs(a + 1, b, c, 0, p))
        {
            return true;
        }
        ans.pop_back();
    }

    if (b < cnt_b)
    {
        ans += 'B';
        if (p != 1)
        {
            if (dfs(a, b + 1, c, 1, p))
            {
                return true;
            }
        }
        ans.pop_back();
    }

    if (c < cnt_c)
    {
        ans += 'C';
        if (p != 2 && pp != 2)
        {
            if (dfs(a, b, c + 1, 2, p))
            {
                return true;
            }
        }
        ans.pop_back();
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> S;
    int size = S.size();
    char c;
    for (int i = 0; i < size; ++i)
    {
        c = S[i];
        if (c == 'A')
        {
            ++cnt_a;
        }
        else if (c == 'B')
        {
            ++cnt_b;
        }
        else
        {
            ++cnt_c;
        }

    }

    if (!dfs(0, 0, 0, -1, -1))
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }

    return 0;
}


