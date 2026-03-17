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
int N;
vector<vector<int>> sectors(11);
int people_cnt[11];
int answer = INF;
bool in_groupA[11];
bool is_visited[11];

void Input()
{
	cin >> N;
	
	for (int i = 1; i <= N; ++i)
	{
		cin >> people_cnt[i];
	}

	int num, value;
	for (int i = 1; i <= N; ++i)
	{
		cin >> num;
		for (int j = 0; j < num; ++j)
		{
			cin >> value;
			sectors[i].push_back(value);
		}
	}
}

int CanGroup(int _curr, int _cnt, bool _is_A)
{
	fill_n(is_visited, 11, false);
	queue<int> q;
	q.push(_curr);
	is_visited[_curr] = true;

	int curr_cnt = 0;
	int sum = 0;
	int c; 

	while (!q.empty())
	{
		c = q.front(); q.pop();
		curr_cnt++;
		sum += people_cnt[c];
		for (int n : sectors[c])
		{
			if (is_visited[n] || in_groupA[n] != _is_A)
			{
				continue;
			}
			is_visited[n] = true;
			q.push(n);
		}
	}

	if (curr_cnt != _cnt)
	{
		return -1;
	}

	return sum;
}

//Find count of people that group A differ B
int FindPeopleCnt(int curr, int cnt)
{
	int curr_b = 0; 
	for (int i = 1; i <= N; ++i)
	{
		if (!in_groupA[i])
		{
			curr_b = i;
			break;
		}
	}
	if (curr_b == 0)
	{
		return -1;
	}

	int sum_A = CanGroup(curr, cnt, true);
	int sum_B = CanGroup(curr_b, N- cnt, false);

	if (sum_A == -1 || sum_B == -1)
	{
		return -1;
	}

	return abs(sum_A - sum_B);
}

void PrintGroup()
{
	cout << "\n";
	for (int i = 1; i <= N; ++i)
	{
		cout << in_groupA[i];
	}
}

void dfs(int curr, int cnt)
{
	if (cnt == N)
		return;

	if (curr > 0)
	{
		int value = FindPeopleCnt(curr, cnt);
		if (value != -1)
		{
			answer = min(answer, value);
		}
	}

	for (int i = curr + 1; i <= N; ++i)
	{
		in_groupA[i] = true;
		//PrintGroup();
		dfs(i, cnt + 1);
		in_groupA[i] = false;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Input();
	dfs(0, 0);

	if (answer == INF)
		cout << -1;
	else
		cout << answer;

	return 0;
}