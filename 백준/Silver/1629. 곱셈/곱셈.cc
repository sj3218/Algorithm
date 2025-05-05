#include <iostream>
#include <algorithm>
using namespace std;

long long mod_pow(long long A, long long B, long long C) {
    if (B == 0) return 1;
    long long half = mod_pow(A, B / 2, C);
    long long result = (half * half) % C;
    if (B % 2 == 1) 
        result = (result * A) % C;
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long A, B, C;
    cin >> A >> B >> C;

    cout << mod_pow(A, B, C);
    return 0;
}