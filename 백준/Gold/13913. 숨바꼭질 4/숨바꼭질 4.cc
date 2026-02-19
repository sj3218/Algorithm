#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int BOARD_MAX = 100000;
int N;
int K;
pair<int,int> is_visited[100001];//pre_pos, time
int route[100001];

void Input()
{
	cin >> N >> K;
}

bool OutOfRange(int x)
{
	if (x < 0 || x > BOARD_MAX)
		return true;

	return false;
}

void FindFastTime()
{
	fill_n(is_visited, 100001, make_pair<int,int>(-1, -1));
	queue<int> q;
	is_visited[N] = { -1, 0 };
	q.push(N);

	int curr_pos;
	int curr_time;
	int next_time;
	int next_pos;
	int pre_pos;
	while (!q.empty())
	{
		curr_pos = q.front();
		q.pop();
		tie(pre_pos, curr_time) = is_visited[curr_pos];

		if (curr_pos == K)
			return;

		for (int n_pos : {curr_pos + 1, curr_pos - 1, curr_pos * 2})
		{
			if (OutOfRange(n_pos))
				continue;

			next_time = is_visited[n_pos].second;

			if (next_time != -1 && next_time <= curr_time + 1)
			{
				continue;
			}

			is_visited[n_pos] = { curr_pos, curr_time + 1 };
			q.push(n_pos);
		}

		/*
		next_pos = curr_pos * 2;
		if (OutOfRange(next_pos))
			continue;

		next_time = is_visited[next_pos].second;
		if (next_time != -1 && next_time <= curr_time)
			continue;

		is_visited[next_pos] = { curr_pos, curr_time };
		q.push(next_pos);*/
	}
}

void BackTrackingRoute()
{
	int pos = K;
	int idx = 0;
	while (pos != -1)
	{
		route[idx++] = pos;
		pos = is_visited[pos].first;
	}

	for (idx -= 1; idx >= 0; --idx)
	{
		cout << route[idx]<<" ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Input();
	FindFastTime();
	cout << is_visited[K].second <<"\n";
	BackTrackingRoute();

	return 0;
}