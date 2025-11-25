#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test_case;
const int TOTAL_STUDENT_CNT = 20;

int Solution()
{
    int move_cnt = 0;
    int idx;

    vector<int> students(TOTAL_STUDENT_CNT,0);
    cin >> students[0];

    for (int i = 1; i < TOTAL_STUDENT_CNT; ++i)
    {
        cin >> students[i];
        if (students[i] > students[i - 1])
            continue;

        idx = upper_bound(students.begin(), students.begin() + i - 1, students[i]) - students.begin();
        move_cnt += (i - idx);
        sort(students.begin(), students.begin() + i+1);
    }

    return move_cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> test_case;
    int num;

    while (test_case--)
    {
        cin >> num;
        cout << num << " ";
        cout << Solution() << "\n";
    }

    return 0;
}