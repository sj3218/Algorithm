#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <map>

#define INF 0X7FFFFFFF
using namespace std;

map<long long, long long> dp;
long long N, P, Q;

long long solve(long long idx)
{
    if (dp[idx] != 0)
    {
        return dp[idx];
    }

    if (idx == 0)
        return dp[idx] = 1;

    return dp[idx] = solve(idx/P) + solve(idx/Q);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> P >> Q;
    cout << solve(N);

    return 0;
}