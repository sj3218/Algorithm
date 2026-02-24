#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <set>
#include <cmath>

using namespace std;

const int MAX_VALUE = 1000000;
const int MOD = 1000000000;

int N;
long long dp[MAX_VALUE + 1];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	dp[0] = 0;
	dp[1] = 1;
	int size = abs(N);

	for (int i = 2; i <= size; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	}

	int value = dp[abs(N)];
	if (N > 0)
	{
		cout << 1 << "\n" << value;
	}
	else if (N == 0)
	{
		cout << "0\n0";
	}
	else
	{
		if (abs(N) % 2 == 0)
		{
			cout << -1 << "\n" << value;
		}
		else
			cout << 1 << "\n" << value;
	}

	return 0;
}