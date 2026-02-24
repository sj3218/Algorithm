#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <set>

using namespace std;

const int INF = 0x7fffffff;
const int MAX_SIZE = 51;
const int EMPTY = 0;
const int WALL = 1;
const int VIRUS = 2;

int board_size;//5<= n <= 50
int virus_cnt;
int board[MAX_SIZE][MAX_SIZE];
bool is_visited[MAX_SIZE][MAX_SIZE]; 
int total_empty_cnt = 0;
vector<pair<int, int>> virus_pos; 
pair<int, int> curr_virus_pos[11];
int min_time = INF;

int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

void Input()
{
	cin >> board_size >> virus_cnt;

	total_empty_cnt = board_size * board_size;

	int value;
	for (int r = 1; r <= board_size; ++r)
	{
		for (int c = 1; c <= board_size; ++c)
		{
			cin >> value;
			board[r][c] = value;
			if (value == VIRUS)
			{
				virus_pos.push_back({ r,c });
			}

			if (value == WALL)
				--total_empty_cnt;
		}
	}
}

bool OutOfBoard(int r, int c)
{
	if (r <= 0 || c <= 0 || r > board_size || c > board_size)
		return true;
	return false;
}

void PrintBoard()
{
	for (int r = 1; r <= board_size; ++r)
	{
		for (int c = 1; c <= board_size; ++c)
		{
			if (is_visited[r][c])
			{
				cout << "2 ";
			}
			else if (board[r][c] == WALL)
				cout << "1 ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int Simulation()
{
	fill_n(&is_visited[0][0], MAX_SIZE * MAX_SIZE, false);
	queue<tuple<int, int, int>> q;
	int r, c, nr, nc, dist;
	int cnt = 0;
	int max_time = 0;

	for (int i = 0; i < virus_cnt; ++i)
	{
		tie(r, c) = curr_virus_pos[i];
		q.push({ r, c, 0 });
		is_visited[r][c] = true;
	}

	while (!q.empty())
	{
		tie(r, c, dist) = q.front(); q.pop();
		++cnt;
		max_time = max(max_time, dist);

		if (cnt == total_empty_cnt)
		{
			return max_time;
		}

		for (int i = 0; i < 4; ++i)
		{
			nr = r + dr[i];
			nc = c + dc[i];

			if (OutOfBoard(nr, nc) || is_visited[nr][nc] || board[nr][nc] == WALL)
				continue;

			q.push({ nr,nc,dist + 1 });
			is_visited[nr][nc] = true;
		}
	}

	return -1;
}

void DFS(int start, int depth)
{
	if (depth == virus_cnt)
	{
		int temp = Simulation();
		if (temp != -1)
			min_time = min(min_time, temp);
		return;
	}

	for (int i = start; i < virus_pos.size(); ++i)
	{
		curr_virus_pos[depth] = virus_pos[i];
		DFS(i + 1, depth + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Input();
	DFS(0, 0);

	if (min_time == INF)
		cout << -1;
	else
		cout << min_time;

	return 0;
}