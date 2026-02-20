#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_BUILDING_CNT = 1001;
int cnt_buildings;
int cnt_rules;
int goal_building;
int build_time[MAX_BUILDING_CNT];
vector<vector<int>> rules(MAX_BUILDING_CNT);

int dp[MAX_BUILDING_CNT];
int indegrees[MAX_BUILDING_CNT];

void Init()
{
	fill_n(dp, MAX_BUILDING_CNT, 0);
	fill_n(indegrees, MAX_BUILDING_CNT, 0);
	fill_n(build_time, MAX_BUILDING_CNT, 0);
	rules = vector<vector<int>>(MAX_BUILDING_CNT);

	cin >> cnt_buildings >> cnt_rules;
	
	for (int i = 1; i <= cnt_buildings; ++i)
	{
		cin >> build_time[i];
	}

	int x, y;
	for (int i = 0; i < cnt_rules; ++i)
	{
		cin >> x >> y;
		rules[x].push_back(y);
		indegrees[y]++;
	}

	cin >> goal_building;
}

int Solution()
{
	queue<int> q;
	//root node
	for (int i = 1; i <= cnt_buildings; ++i)
	{
		if (indegrees[i] == 0)
		{
			q.push(i);
			dp[i] = build_time[i];
		}
	}

	int curr;
	while (!q.empty())
	{
		curr = q.front(); q.pop();

		for (int next : rules[curr])
		{
			indegrees[next]--;
			dp[next] = max(dp[next], dp[curr] + build_time[next]);
			if (indegrees[next] == 0)
				q.push(next);
		}
	}

	return dp[goal_building];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		Init();
		cout << Solution() << "\n";
	}

	return 0;
}