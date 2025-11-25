#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int H, W, N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> H >> W >> N >> M;

    int w_cnt = W / (M + 1);
    int mod = W % (M + 1);
    if (mod != 0 && mod <= M)
        w_cnt++;

    int h_cnt = H / (N + 1);
    mod = H % (N + 1);
    if (mod != 0 && mod <= N)
        ++h_cnt;

    cout << w_cnt * h_cnt;

    return 0;
}