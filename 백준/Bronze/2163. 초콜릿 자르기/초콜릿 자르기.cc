#include <iostream>
using namespace std;

int N, M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    cout << (M - 1) + M * (N - 1);
    return 0;
}