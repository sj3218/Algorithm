#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int N;
string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    cin >> S;
    
    int ans = 0;
    for(int i = 0; i < N; ++i)
    {
        ans += S[i] - '0';
    }

    cout << ans;
    return 0;
}