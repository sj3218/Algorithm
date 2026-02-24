#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <set>

using namespace std;

int MOD = 10007;
const int MAX_VALUE = 1000;
int dp[10]; //the end of the digit
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	for (int i = 0; i <= 9; ++i)
	{
		dp[i] = 1;
	}

	for (int i = 2; i <= N; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			dp[j] = (dp[j] + dp[j - 1]) % MOD;

		}
	}

	int sum = 0;
	for (int i = 0; i <= 9; ++i)
	{
		sum += dp[i];
	}
	cout << sum%MOD;
	
	return 0;
}