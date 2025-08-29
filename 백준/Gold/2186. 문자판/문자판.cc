#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

int Row, Col;
int total_move_length;
string s;
string word;
char board[101][101];
int answer = 0;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

int dp[101][101][90];

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > Row || c > Col)
        return true;
    return false;
}

int dfs(int word_idx, int r, int c)
{
    if (dp[r][c][word_idx] != -1)
        return dp[r][c][word_idx]; 

    if (board[r][c] != word[word_idx])
        return 0;

    if (word_idx == word.size() - 1)
        return 1;

    int nr, nc;
    int sum = 0;
    for (int i = 1; i <= total_move_length; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            nr = r + dr[j] * i;
            nc = c + dc[j] * i;

            if (OutOfBound(nr, nc))
                continue;

            sum += dfs(word_idx + 1, nr, nc);
        }
    }

    dp[r][c][word_idx] = sum;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> Row >> Col >> total_move_length;
    fill_n(&dp[0][0][0], 101 * 101 * 90, -1);

    for (int r = 1; r <= Row; ++r)
    {
        cin >> s;
        for (int c = 1; c <= Col; ++c)
        {
            board[r][c] = s[c - 1];
        }
    }
    cin >> word;

    for (int r = 1; r <= Row; ++r)
    {
        for (int c = 1; c <= Col; ++c)
        {
            answer += dfs(0, r, c);
        }
    }

    cout << answer;

    return 0;
}