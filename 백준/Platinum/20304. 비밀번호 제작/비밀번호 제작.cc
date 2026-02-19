#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

const int SIZE = 1000001;
const int MAX_BIT = 20;
int max_password, cnt_password;
int password[SIZE];
int dist[SIZE];
queue<int> q;

void Init()
{
	cin >> max_password >> cnt_password;
	fill_n(dist, SIZE, -1);

	for (int i = 0; i < cnt_password; ++i)
	{
		cin >> password[i];
		q.push(password[i]);
		dist[password[i]] = 0;
	}
}

int FindSaftyPassword()
{
	int c_pwd;
	int n_pwd;
	int c_safty;
	while (!q.empty())
	{
		c_pwd = q.front();
		q.pop();
		c_safty = dist[c_pwd];
		for (int bit = 0; bit <= MAX_BIT; ++bit)
		{
			n_pwd = c_pwd ^ (1 << bit);

			if (n_pwd > max_password)
				continue;
			if (dist[n_pwd] != -1)
				continue;

			q.push(n_pwd);
			dist[n_pwd] = c_safty + 1;
		}
	}

	//find high value of safty
	int ans = 0;
	for (int i = 0; i <= max_password; ++i)
	{
		ans = max(ans, dist[i]);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	Init();
	cout << FindSaftyPassword();

	return 0;
}