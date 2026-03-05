#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <set>

using namespace std;

int N, M, D;
int original_board[20][20];
int temp_board[20][20];
int is_visited[20][20];
int archer_cnt = 3;
int enemies_cnt;
int answer = 0;

int dr[3] = { 0,-1,0 };
int dc[3] = { -1,0,1 };

void Input()
{
	cin >> N >> M >> D;

	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= M; ++c)
		{
			cin >> original_board[r][c];
			if (original_board[r][c] == 1)
				++enemies_cnt;
		}
	}
}

bool OutOfBound(int r, int c)
{
	if (r <= 0 || c <= 0 || r > N || c > M)
		return true;
	return false;
}

void Initialize()
{
	for (int r = 1; r <= N; ++r)
	{
		for (int c = 1; c <= M; ++c)
		{
			temp_board[r][c] = original_board[r][c];
		}
	}
}

pair<int,int> Shot(int archer_pos)
{
	queue<pair<int, int>> q;
	q.push({ N + 1, archer_pos });
	
	int cc, cr, nr, nc;
	int dist;
	while (!q.empty())
	{
		tie(cr, cc) = q.front();
		q.pop();
		dist = is_visited[cr][cc];
		
		if (dist > D)
			continue;

		if (temp_board[cr][cc] == 1)
		{
			return { cr,cc };
		}

		for (int i = 0; i < 3; ++i)
		{
			nr = cr + dr[i];
			nc = cc + dc[i];

			if (OutOfBound(nr, nc) || is_visited[nr][nc] != 0)
				continue;
			
			is_visited[nr][nc] = dist + 1;
			q.push({ nr,nc });
		}
	}

	return { 0,0 };
}

int MoveEnemy()
{
	int cnt = 0;
	for (int r = N; r > 1; --r)
	{
		for (int c = 1; c <= M; ++c)
		{
			if (r == N && temp_board[r][c] == 1)
			{
				++cnt;
			}
			temp_board[r][c] = temp_board[r - 1][c];
		}
	}

	for (int c = 0; c <= M; ++c)
	{
		temp_board[1][c] = 0;
	}

	return cnt;
}

int Simulation(vector<int>& archer_pos)
{
	int dead_enemies_cnt = 0;
	int total_enemies_cnt = enemies_cnt;
	int temp_dead_enemies_cnt = 0;
	int r, c;

	Initialize();
	
	pair<int, int> enemy_pos;
	while (total_enemies_cnt > 0)
	{
		set<pair<int, int>> enemies_pos;

		//1. attack enemy (using bfs)
		for (int i = 0; i < archer_cnt; ++i)
		{
			fill_n(&is_visited[0][0], 20 * 20, 0);
			enemy_pos = Shot(archer_pos[i]);

			if (enemy_pos.first == 0 && enemy_pos.second == 0)
				continue;

			enemies_pos.insert(enemy_pos);
		}
		temp_dead_enemies_cnt = enemies_pos.size();

		//2. update board 
		for (pair<int, int> pos : enemies_pos)
		{
			tie(r, c) = pos;
			temp_board[r][c] = 0;
		}
		
		//3. move enemy
		total_enemies_cnt -= MoveEnemy();

		//4. update values
		total_enemies_cnt -= temp_dead_enemies_cnt;
		dead_enemies_cnt += temp_dead_enemies_cnt;
	}
	
	return dead_enemies_cnt;
}

void Find_ArcherPos(int depth, int start, vector<int>& pos)
{
	if (depth == archer_cnt)
	{
		answer = max(answer, Simulation(pos));
		return;
	}

	for (int c = start; c <= M; ++c)
	{
		pos[depth] = c;
		Find_ArcherPos(depth + 1, c + 1, pos);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Input();
	vector<int> archer_pos(3);

	Find_ArcherPos(0, 1, archer_pos);
	cout << answer;

	return 0;
}