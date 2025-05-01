#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

int N, K;
int m, v;
int max_weight;
pair<int, int> jewel[300001];
multiset<int> bag;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        cin >> m >> v;
        jewel[i].first = v;
        jewel[i].second = m;
    }

    sort(jewel, jewel + N);

    for (int i = 0; i < K; ++i)
    {
        cin >> max_weight;
        bag.insert(max_weight);
    }

    long long answer = 0;

    for (int i = N - 1; i >= 0; --i)
    {
        tie(v,m) = jewel[i];
        multiset<int>::iterator it = bag.lower_bound(m);
        if (it == bag.end())
            continue;
        answer += v;
        bag.erase(it);
    }

    cout << answer;
    return 0;
}
