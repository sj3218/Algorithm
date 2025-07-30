#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

#define INF 0X7FFFFFFF
using namespace std;

int test_case;
int cnt;
bool is_deleted[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> test_case;
    while (test_case--)
    {
        cin >> cnt;
        char oper;
        int num;
        fill_n(is_deleted, 1000001, false);
        priority_queue<pair<int, int>> greater_q;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> less_q;

        for (int i = 0; i < cnt; ++i)
        {
            cin >> oper >> num;

            if (oper == 'I')
            {
                greater_q.push({ num, i });
                less_q.push({ num,i });
            }
            else
            {
                if (num < 0)
                {
                    //delete less one
                    int value, idx;
                    while (!less_q.empty())
                    {
                        tie(value, idx) = less_q.top();
                        less_q.pop();
                        if (is_deleted[idx])
                            continue;

                        is_deleted[idx] = true;

                        break;
                    }
                }
                else
                {
                    //delete greater one
                    int value, idx;
                    while (!greater_q.empty())
                    {
                        tie(value, idx) = greater_q.top();
                        greater_q.pop();
                        if(is_deleted[idx])
                            continue;

                        is_deleted[idx] = true;
                        break;
                    }
                }
            }


        }

        int idx;
        int min_value, max_value;
        bool is_empty = true;

        while (!less_q.empty())
        {
            tie(num, idx) = less_q.top();
            less_q.pop();
            if (is_deleted[idx])
                continue;

            min_value = num;
            is_empty = false;
            break;
        }
        
        while (!greater_q.empty())
        {
            tie(num, idx) = greater_q.top();
            greater_q.pop();
            if (is_deleted[idx])
                continue;
            max_value = num;
            break;
        }

        if (is_empty)
            cout << "EMPTY\n";
        else
            cout << max_value << " " << min_value << "\n";

    }
    return 0;
}