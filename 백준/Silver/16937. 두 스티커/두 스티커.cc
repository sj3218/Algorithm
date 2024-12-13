#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int H, W, N;
vector<pair<int, int>> stickers;

bool CanPlaceBoth(int h1, int h2, int w1, int w2)
{
    if (w1 + w2 <= W && max(h1, h2) <= H)
        return true;

    if (h1 + h2 <= H && max(w1, w2) <= W)
        return true;

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> H >> W >> N;
    int r, c;
    int max_side = max(H, W);

    for (int i = 0; i < N; ++i)
    {
        cin >> r >> c;
        if (max(r, c) > max_side)
        {
            continue;
        }

        stickers.push_back({ r,c });
    }

    int max_area = 0;
    N = stickers.size();

    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            pair<int, int> A, B;
            A = stickers[i];
            B = stickers[j];

            for (int r1 = 0; r1 < 2; ++r1)
            {
                for (int r2 = 0; r2 < 2; ++r2)
                {
                    if (CanPlaceBoth(A.first, B.first, A.second, B.second))
                    {
                        max_area = max(max_area, A.first * A.second + B.first * B.second);
                    }
                    B = { B.second, B.first };
                }
                A = { A.second, A.first };
            }
        }

    }

    cout << max_area;
    return 0;
}