#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <set>


using namespace std;

const int INF = 0X7FFFFFFF;
int N, M, K;
int board[7][51][51];
tuple<int, int, int> rotate_info[7];
bool is_visited[7];
int answer = INF;

void Input()
{
	cin >> N >> M >> K;
	
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> board[0][i][j];
		}
	}

	int r, c, s;
	for (int i = 1; i <= K; ++i)
	{
		cin >> r >> c >> s;
		rotate_info[i] = { r,c,s };
	}
}

void RotateBoard(int idx, int rotate_idx)
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			board[idx][i][j] = board[idx - 1][i][j];
		}
	}

	int R, C, S;
	tie(R, C, S) = rotate_info[rotate_idx];

	int start_c, end_c, start_r, end_r;
	
	for (int s = 1; s <= S; ++s)
	{
		start_c = C - s;
		end_c = C + s;
		start_r = R - s;
		end_r = R + s;
		//top
		for (int c = start_c + 1; c <= end_c; ++c)
		{
			board[idx][start_r][c] = board[idx - 1][start_r][c - 1];
		}
		//bottom
		for (int c = end_c - 1; c >= start_c; --c)
		{
			board[idx][end_r][c] = board[idx - 1][end_r][c + 1];
		}
		//left
		for (int r = end_r - 1; r >= start_r; --r)
		{
			board[idx][r][start_c] = board[idx - 1][r + 1][start_c];
		}
		//right
		for (int r = start_r + 1; r <= end_r; ++r)
		{
			board[idx][r][end_c] = board[idx - 1][r - 1][end_c];
		}
	}
}

void FindMinimunRow()
{
	int sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		sum = 0;
		for (int j = 1; j <= M; ++j)
		{
			sum += board[K][i][j];
		}
		answer = min(answer, sum);
	}
}

void PrintBoard(int idx)
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cout << board[idx][i][j]<<" ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void FindOrder(int idx)
{
	if (idx > K)
	{
		FindMinimunRow();
		return;
	}

	for (int i = 1; i <= K; ++i)
	{
		if (is_visited[i])
			continue;

		is_visited[i] = true;
		RotateBoard(idx, i);
		//PrintBoard(i);
		FindOrder(idx + 1);
		is_visited[i] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Input();
	FindOrder(1);
	cout << answer;

	return 0;
}