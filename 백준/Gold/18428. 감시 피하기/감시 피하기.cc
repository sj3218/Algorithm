#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define INF 0x7fffffff
using namespace std;

const int EMPTY = 0;
const int STUDENT = 1;
const int TEACHER = 2;
const int WALL = 3;
int N;
int board[7][7];
vector<pair<int, int>> teacher_pos;
vector<pair<int, int>> positions;
vector<pair<int, int>> selected;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void Input()
{
    cin >> N;
    char ch;
    for (int r = 1; r <= N; ++r)
    {
        for (int c = 1; c <= N; ++c)
        {
            cin >> ch;
            if (ch == 'S')
                board[r][c] = STUDENT;
            else if (ch == 'T')
            {
                teacher_pos.push_back({ r,c });
                board[r][c] = TEACHER;
            }
            else
                positions.push_back({ r,c });
        }
    }
}

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > N || c > N)
        return true;
    return false;
}

bool WhichWay(int r, int c, int i)
{
    while (true)
    {
        r += dx[i];
        c += dy[i];
        if (OutOfBound(r, c))
            break;
        if (board[r][c] == WALL)
            break;

        if (board[r][c] == STUDENT)
            return true;
    }
    return false;
}
bool DetectStudents()
{
    int r, c;
    for (pair<int, int> pos : teacher_pos)
    {
        tie(r, c) = pos;
        for (int i = 0; i < 4; ++i)
        {
            if (WhichWay(r, c, i))
                return true;
        }
    }
    return false;
}

bool Combi(int start, int cnt)
{
    if (cnt == 3)
    {
        if (DetectStudents())
        {
            return false;
        }
        return true;
    }

    for (int i = start; i < positions.size(); ++i)
    {
        board[positions[i].first][positions[i].second] = WALL;
        if (Combi(i + 1, cnt + 1))
            return true;
        board[positions[i].first][positions[i].second] = EMPTY;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    if (Combi(0, 0))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}