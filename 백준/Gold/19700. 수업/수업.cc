#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <tuple>

using namespace std;

int N;
pair<int, int> info[500001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int h, k;

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> h >> k;
        info[i].first = h;
        info[i].second = k;
    }

    sort(info, info + N, greater<pair<int, int>>()); //키 순서대로 정렬
    multiset<int> s;

    for (int i = 0; i < N; i++) {
        multiset<int>::iterator it = s.lower_bound(-info[i].second + 1); // x-1명 이하인 팀 중에서 팀원 수 가장 많은 팀 구하기
        if (it == s.end()) 
            s.insert(-1);//팀이 없을 시 새로운 팀 배정
        else 
        {
            //팀이 있을 시 팀 배정
            int val = *it;

            s.erase(it);
            s.insert(val - 1);
            //팀 배정 후 s에는 -등수로 찍힘, 
            //한 팀에 3명 들어가면 -3, 2명 들어가면 -2 이런식으러
        }
    }

    cout << s.size();
    return 0;
}
