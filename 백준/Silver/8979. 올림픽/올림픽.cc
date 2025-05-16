#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int N;
int K;
vector<tuple<int, int, int, int>> medals;

bool compare(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b)
{
    if (get<0>(a) != get<0>(b))
        return get<0>(a) > get<0>(b);

    if (get<1>(a) != get<1>(b))
        return get<1>(a) > get<1>(b);

    if (get<2>(a) != get<2>(b))
        return get<2>(a) > get<2>(b);

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;
    int n, a, b, c;
    for (int i = 1; i <= N; ++i)
    {
        cin >> n >> a >> b >> c;
        medals.push_back({ a, b, c, n });
    }

    sort(medals.begin(), medals.end(), compare);

    int answer = 1;

    for (int i = 0; i < N; ++i)
    {
        if (get<3>(medals[i]) != K)
            continue;

        int g = get<0>(medals[i]);
        int s = get<1>(medals[i]);
        int b = get<2>(medals[i]);

        for (int j = 0; j < N; ++j)
        {
            if (i == j)
                break;

            if (get<0>(medals[j]) > g)
                ++answer;
            else if (get<0>(medals[j]) == g)
            {
                if (get<1>(medals[j]) > s)
                    ++answer;
                else if (get<1>(medals[j]) == s)
                {
                    if (get<2>(medals[j]) > b)
                        ++answer;
                }
            }
        }
        break;
    }

    cout << answer;

    return 0;
}