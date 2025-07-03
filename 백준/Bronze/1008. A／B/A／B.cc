#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a, b;
    double k;
    cin >> a >> b;
    k = double(a) / double(b);
    cout.precision(10);
    cout << k;
    return 0;
}