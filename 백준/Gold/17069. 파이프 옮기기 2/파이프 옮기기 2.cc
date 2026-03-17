#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <set>

using namespace std;

bool board[35][35];
int N;
long long answer = 0;
long long dp[35][35][3];

void Input()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> board[i][j];
		}
	}
}

bool OutOfBound(int r, int c)
{
	if (r <= 0 || c <= 0 || r > N || c > N)
	{
		return true;
	}
	return false;
}

void DP()
{
	dp[1][2][0] = 1;
	int dr, dc;
	bool _next = false;
	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= N; ++c)
		{
			if (board[r][c])
				continue;

			if (dp[r][c][0] != 0)
			{
				if (board[r][c + 1] == 0)
				{
					dp[r][c + 1][0] += dp[r][c][0];
				}
				if (board[r][c + 1] == 0 && board[r + 1][c + 1] == 0 && board[r + 1][c] == 0)
				{
					dp[r + 1][c + 1][2] += dp[r][c][0];
				}
			}

			if (dp[r][c][1] != 0)
			{
				if (board[r+1][c] == 0)
				{
					dp[r+1][c][1] += dp[r][c][1];
				}
				if (board[r][c + 1] == 0 && board[r + 1][c + 1] == 0 && board[r + 1][c] == 0)
				{
					dp[r + 1][c + 1][2] += dp[r][c][1];
				}
			}

			if (dp[r][c][2] != 0)
			{
				if (board[r][c + 1] == 0)
				{
					dp[r][c + 1][0] += dp[r][c][2];
				}
				if (board[r + 1][c] == 0)
				{
					dp[r + 1][c][1] += dp[r][c][2];
				}
				if (board[r][c + 1] == 0 && board[r + 1][c + 1] == 0 && board[r + 1][c] == 0)
				{
					dp[r + 1][c + 1][2] += dp[r][c][2];
				}
			}
		}
	}
}

void print_board()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int r = 1; r <= N; ++r)
		{
			for (int c = 1; c <= N; ++c)
			{
				cout << dp[r][c][i] << " ";
			}
			cout << "\n";
		}

		cout << "\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Input();
	DP();
	answer = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
	//print_board();
	cout << answer;

	return 0;
}