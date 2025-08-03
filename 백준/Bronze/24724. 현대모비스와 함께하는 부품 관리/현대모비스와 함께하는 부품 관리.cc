#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

#define INF 0X7FFFFFFF
using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    int N, A, B;
    int u, v;
    
    for (int process = 1; process <= T; ++process)
    {
        cout << "Material Management " << process << "\n";
        cin >> N >> A >> B;
        for (int i = 0; i < N; ++i)
            cin >> u >> v;
        cout << "Classification ---- End!\n";
    }

    return 0;
}