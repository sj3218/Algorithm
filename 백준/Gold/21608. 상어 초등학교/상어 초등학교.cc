#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <deque>

#define MAX_STUDENT_COUNT       21
#define LIKE_STUDENT_COUNT      4
#define SATISFIED_ZERO          0
#define SATISFIED_ONE           1
#define SATISFIED_TWO           10
#define SATISFIED_THREE         100
#define SATISFIED_FOUR          1000

using namespace std;

int student_cnt;
int board[MAX_STUDENT_COUNT][MAX_STUDENT_COUNT];
vector<pair<int, vector<int>>> students;
int students_idx[MAX_STUDENT_COUNT * MAX_STUDENT_COUNT + 10];

int answer = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > student_cnt || y > student_cnt)
        return false;
    return true;
}

void CalcSatisfied()
{
    int cnt;
    int r, c;
    int student_id;
    int idx;
    int n_student_id;
    for (int i = 1; i <= student_cnt; ++i)
    {
        for (int j = 1; j <= student_cnt; ++j)
        {
            cnt = 0;
            student_id = board[i][j];
            idx = students_idx[student_id];

            for (int k = 0; k < 4; ++k)
            {
                r = i + dx[k];
                c = j + dy[k];

                if (!IsValid(r, c))
                    continue;
                
                n_student_id = board[r][c];

                if (n_student_id == students[idx].second[0] || n_student_id == students[idx].second[1] ||
                    n_student_id == students[idx].second[2] || n_student_id == students[idx].second[3])
                    ++cnt;
            }

            if (cnt == 0)
                answer += SATISFIED_ZERO;
            else if (cnt == 1)
                answer += SATISFIED_ONE;
            else if (cnt == 2)
                answer += SATISFIED_TWO;
            else if (cnt == 3)
                answer += SATISFIED_THREE;
            else
                answer += SATISFIED_FOUR;
        }
    }
}

void Input()
{
    cin >> student_cnt;

    int id, a, b, c, d;
    int cnt = 0;
    for (int i = 1; i <= student_cnt; ++i)
    {
        for (int j = 1; j <= student_cnt; ++j)
        {
            cin >> id >> a >> b >> c >> d;

            students.push_back({ id, {a,b,c,d} });
            students_idx[id] = cnt++;
        }
    }
}

pair<int, int> FindSeat(int id, vector<int> favorite_students)
{
    vector<tuple<int,int,int,int>> all_seats; // favorite_cnt, empty_cnt, r,c

    int favorite_cnt, empty_cnt, r, c;
    int nx, ny;
    int n_student;
    int max_favorite_cnt = 0;
    for (int i = 1; i <= student_cnt; ++i)
    {
        for (int j = 1; j <= student_cnt; ++j)
        {
            if (board[i][j] != 0)
                continue;

            favorite_cnt = 0;
            empty_cnt = 0;

            for (int k = 0; k < 4; ++k)
            {
                nx = i + dx[k];
                ny = j + dy[k];
                if (!IsValid(nx, ny))
                    continue;

                n_student = board[nx][ny];
                if (n_student == 0)
                    ++empty_cnt;
                else if (favorite_students[0] == n_student || favorite_students[1] == n_student ||
                    favorite_students[2] == n_student || favorite_students[3] == n_student)
                    ++favorite_cnt;
            }
            max_favorite_cnt = max(max_favorite_cnt, favorite_cnt);
            all_seats.push_back({ favorite_cnt, empty_cnt, i,j });
        }
    }

    vector<tuple<int, int, int>> favorite_seats;
    int max_empty_cnt = 0;
    for (tuple<int, int, int, int> seat : all_seats)
    {
        tie(favorite_cnt, empty_cnt, r, c) = seat;
        if (favorite_cnt == max_favorite_cnt)
        {
            favorite_seats.push_back({ empty_cnt, r,c });
            max_empty_cnt = max(max_empty_cnt, empty_cnt);
        }
    }

    vector<pair<int, int>> seats;
    for (tuple<int, int, int> seat : favorite_seats)
    {
        tie(empty_cnt, r, c) = seat;
        if (empty_cnt == max_empty_cnt)
            seats.push_back({ r,c });
    }
    sort(seats.begin(), seats.end());

    return seats[0];
}

void Solution()
{
    pair<int, int> seat;
    
    for (pair<int, vector<int>> student : students)
    {
        seat = FindSeat(student.first, student.second);
        board[seat.first][seat.second] = student.first;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    Solution();
    CalcSatisfied();

    cout << answer;

    return 0;
}