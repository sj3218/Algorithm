#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <set>

using namespace std;

const int INF = 0x7fffffff;
const int MAX_SIZE = 1000;

int ROW, COL;
const int U = 0;
const int D = 1;
const int L = 2;
const int R = 3;

const int EMPTY = 0;
const int PROCESSING = 1;
const int COMPLETE = 2;

char board[MAX_SIZE + 1][MAX_SIZE + 1];
int is_visited[MAX_SIZE + 1][MAX_SIZE + 1]; //0: x, 1: processing, 2: complete

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

/*

4 4
RDLL
ULLL
RDRD
ULUL

*/
void Input()
{
	cin >> ROW >> COL;
	string s;

	for (int r = 1; r <= ROW; ++r)
	{
		cin >> s;
		for (int c = 1; c <= COL; ++c)
		{
			board[r][c] = s[c - 1];
		}
	}
}

bool OutOfBoard(int r, int c)
{
	if (r <= 0 || c <= 0 || r > ROW || c > COL)
		return true;
	return false;
}

bool DFS(int r, int c)
{
	int nr, nc, idx;
	switch (board[r][c])
	{
	case 'U':
		idx = U;
		break;
	case 'D':
		idx = D;
		break;
	case 'L':
		idx = L;
		break;
	case 'R':
		idx = R;
		break;
	}
	nr = r + dr[idx];
	nc = c + dc[idx];

	if (is_visited[nr][nc] == EMPTY)
	{
		is_visited[nr][nc] = PROCESSING;
		if (DFS(nr, nc))
		{
			is_visited[nr][nc] = COMPLETE;
		}
		else
		{
			is_visited[nr][nc] = EMPTY;
			return false;
		}
	}
	else if (is_visited[nr][nc] == COMPLETE)
	{
		return false;
	}

	return true;
}

int Solution()
{
	int cnt = 0;

	for (int r = 1; r <= ROW; ++r)
	{
		for (int c = 1; c <= COL; ++c)
		{
			if (is_visited[r][c] == COMPLETE)
				continue;

			is_visited[r][c] = PROCESSING;
			if(DFS(r, c))
				++cnt;
			is_visited[r][c] = COMPLETE;
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Input();
	cout << Solution();

	return 0;
}