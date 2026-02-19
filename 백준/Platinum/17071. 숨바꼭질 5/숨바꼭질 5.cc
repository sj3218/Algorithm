#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int BOARD_MAX = 500000;
int N;
int K;
int is_visited[2][BOARD_MAX + 1];

void Init()
{
	cin >> N >> K;
	fill_n(&is_visited[0][0], 2 * (BOARD_MAX + 1), -1);
}

bool OutOfRange(int x)
{
	if (x < 0 || x > BOARD_MAX)
		return true;

	return false;
}

int FindFastTime()
{
	queue<pair<int, int>> q;
	q.push({ 0, N });
	is_visited[0][N] = 0;
	int c_pos, c_time, n_time;

	while (!q.empty())
	{
		tie(c_time, c_pos) = q.front();
		q.pop();

		n_time = c_time + 1;

		for (int n_pos : {c_pos - 1, c_pos + 1, c_pos * 2})
		{
			if (OutOfRange(n_pos))
				continue;
			if (is_visited[n_time % 2][n_pos] != -1)
				continue;

			is_visited[n_time % 2][n_pos] = n_time;
			q.push({ n_time, n_pos });
		}
	}

	int ans = 0;
	while (K <= BOARD_MAX)
	{
		if (is_visited[ans % 2][K] <= ans)
		{
			return ans;
		}

		K += ++ans;
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Init();
	cout << FindFastTime();
	 
	return 0;
}