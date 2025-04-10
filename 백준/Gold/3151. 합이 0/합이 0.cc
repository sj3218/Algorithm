#include <iostream>
#include <algorithm>
using namespace std;

int N;
int skills[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> skills[i];
    }

    sort(skills, skills+N);

    long long answer = 0;
    int sum;
    
    for (int i = 0; i < N - 2; ++i)
    {
        for (int j = i + 1; j < N - 1; ++j)
        {
            sum = -skills[i] - skills[j];
            int lower = lower_bound(skills + j + 1, skills + N, sum) - skills;
            int upper = upper_bound(skills + j + 1, skills + N, sum) - skills;

            answer += upper - lower;

        }
    }
    cout << answer;
    return 0;
}