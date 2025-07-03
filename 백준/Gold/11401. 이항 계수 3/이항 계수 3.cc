#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007

int N, K;
long long dp[4000001];

long long power(long long base, long long exp)
{
    long long result = 1;

    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = result * base % MOD;

        base = base * base % MOD;
        exp /= 2;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    dp[0] = 1;
    for (int i = 1; i <= N; ++i)
    {
        dp[i] = dp[i - 1] * i % MOD;
    }

    long long numerator = dp[N];
    long long denominator = dp[N - K] * dp[K] % MOD;
    long long inverse_denominator = power(denominator, MOD - 2);
    cout << numerator * inverse_denominator % MOD;
    return 0;
}