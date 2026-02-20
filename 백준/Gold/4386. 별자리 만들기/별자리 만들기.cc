#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

const int MAX_STARS = 101;
int star_cnt;
pair<float, float> star_pos[MAX_STARS];
float star_distance[MAX_STARS][MAX_STARS];
bool is_visited[MAX_STARS];

void Input()
{
	cin >> star_cnt;
	float x, y;
	for (int i = 1; i <= star_cnt; ++i)
	{
		cin >> x >> y;
		star_pos[i] = { x, y };
	}
}

float CalculateDistance(int idx_1, int idx_2)
{
	int x_1, x_2, y_1, y_2;
	tie(x_1, y_1) = star_pos[idx_1];
	tie(x_2, y_2) = star_pos[idx_2];
	
	return sqrt(pow((x_1 - x_2), 2) + pow((y_1 - y_2), 2));
}

void Initialize()
{
	for (int i = 1; i <= star_cnt; ++i)
	{
		for (int j = i + 1; j <= star_cnt; ++j)
		{
			star_distance[i][j] = CalculateDistance(i, j);
			star_distance[j][i] = star_distance[i][j];
		}
	}
}

float PrimAlgorithm()
{
	priority_queue<pair<float, int>, vector<pair<float,int>>, greater<pair<float,int>>> pq;

	pq.push({ 0,1 });
	
	float rst = 0;
	int cnt = 0;
	float dist;
	int curr;
	while (!pq.empty())
	{
		tie(dist, curr) = pq.top(); pq.pop();
		
		if (is_visited[curr])
			continue;
		
		is_visited[curr] = true;
		rst += dist;
		++cnt;
		
		if (cnt == star_cnt)
		{
			return rst;
		}
		
		for (int i = 1; i <= star_cnt; ++i)
		{
			if (is_visited[i])
				continue;
			pq.push({ star_distance[curr][i], i });
		}
	}
	return rst;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	Input();
	Initialize();
	cout << fixed << setprecision(2) << PrimAlgorithm();

	return 0;
}