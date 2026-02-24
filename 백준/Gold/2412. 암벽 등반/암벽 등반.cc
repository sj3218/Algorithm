#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <set>

using namespace std;

//2412번

const int MAX_X = 1000000;
const int MAX_Y = 200000;
int N, T;
map<int, set<int>> homes;

void Init()
{
	cin >> N >> T;
	int x, y;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		homes[x].insert(y);
	}
}

int Solution()
{
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	int x, y, dist;
	set<int>::iterator it;
	int ny;
	while (!q.empty())
	{
		tie(x, y, dist) = q.front();
		q.pop();

		if (y == T)
		{
			return dist;
		}

		for (int nx = x - 2; nx <= x + 2; ++nx)
		{
			if (nx < 0 || nx > MAX_X)
				continue;

			if (homes.find(nx) == homes.end())
				continue;

			it = homes[nx].lower_bound(y - 2);
			while (it != homes[nx].end() && *it <= y + 2)
			{
				ny = *it;
				q.push({ nx, ny, dist + 1 });
				++it;
				homes[nx].erase(ny);
			}

			if (homes[nx].size() == 0)
				homes.erase(nx);
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Init();
	cout << Solution();
	return 0;
}