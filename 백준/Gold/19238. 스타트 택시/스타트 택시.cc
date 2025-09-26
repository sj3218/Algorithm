#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;
#define INF 0X7FFFFFFF

const int WALL = -2;
const int EMPTY = -1;
struct pos
{
    int r;
    int c;
};

int N, M;
int amount_fuel;
int board[21][21];
pos taxi;
vector<pos> customers_start_pos;
vector<pos> customers_goal_pos;
int is_visited[21][21];

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

void Input()
{
    cin >> N >> M;
    cin >> amount_fuel;

    int temp;
    for (int r = 1; r <= N; ++r)
    {
        for (int c = 1; c <= N; ++c)
        {
            cin >> temp;
            if (temp == 0)
                board[r][c] = EMPTY;
            else
                board[r][c] = WALL;
        }
    }

    int a, b, c, d;
    cin >> a >> b;
    taxi = { a,b };

    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c >> d;
        customers_start_pos.push_back({ a,b });
        customers_goal_pos.push_back({ c,d });
        board[a][b] = i;
    }
}

bool OutOfBound(int r, int c)
{
    if (r <= 0 || c <= 0 || r > N || c > N)
        return true;
    return false;
}

int FindNearCustomer()
{
    fill_n(&is_visited[0][0], 21 * 21, -1);
    queue<pos> q;
    q.push(taxi);
    is_visited[taxi.r][taxi.c] = 0;
    int curr_dist = 0;
    pos curr, next;
    int c, n;
    vector<int> customers;
    int min_dist = INF;

    while (!q.empty())
    {
        curr = q.front(); q.pop();
        c = board[curr.r][curr.c];
        curr_dist = is_visited[curr.r][curr.c];

        if (c != WALL && c != EMPTY)
        {
            if (min_dist == INF)
            {
                min_dist = curr_dist;
                customers.push_back(c);
                continue;
            }
            else if (min_dist == curr_dist)
                customers.push_back(c);
        }

        if (min_dist < curr_dist)
            continue;

        for (int i = 0; i < 4; ++i)
        {
            next.r = curr.r + dr[i];
            next.c = curr.c + dc[i];
            n = board[next.r][next.c];

            if (OutOfBound(next.r, next.c) || n == WALL || is_visited[next.r][next.c] != -1)
                continue;

            is_visited[next.r][next.c] = curr_dist + 1;
            q.push({ next });
        }
    }

    if (customers.size() == 0)
        return -1;

    int curr_idx = customers[0];
    int idx = curr_idx;
    int cr = customers_start_pos[curr_idx].r;
    int cc = customers_start_pos[curr_idx].c;
    int nr, nc;
    
    for (int i = 1; i < customers.size(); ++i)
    {
        curr_idx = customers[i];
        nr = customers_start_pos[curr_idx].r;
        nc = customers_start_pos[curr_idx].c;

        if (nr > cr)
        {
            continue;
        }
        else if (nr == cr)
        {
            if (nc > cc)
            {
                continue;
            }
        }

        idx = curr_idx;
        cr = nr;
        cc = nc;
    }

    return idx;
}

bool MoveToDestination(pos start, pos goal)
{
    fill_n(&is_visited[0][0], 21 * 21, -1);

    queue<pos> q;
    q.push(start);
    is_visited[start.r][start.c] = 0;

    pos curr, next;
    int fuel;

    while (!q.empty())
    {
        curr = q.front(); q.pop();
        fuel = is_visited[curr.r][curr.c];
        if (curr.r == goal.r && curr.c == goal.c)
        {
            amount_fuel -= fuel;
            if (amount_fuel < 0)
                return false;

            return true;
        }

        for (int i = 0; i < 4; ++i)
        {
            next.r = curr.r + dr[i];
            next.c = curr.c + dc[i];

            if (OutOfBound(next.r, next.c) || board[next.r][next.c] == WALL || is_visited[next.r][next.c] != -1)
                continue;

            is_visited[next.r][next.c] = fuel + 1;
            q.push(next);
        }
    }

    return false;
}

void Solution()
{
    int total_customer = 0;
    int curr_dist = 0;
    pos start_pos;
    pos goal_pos;

    while (total_customer < M)
    {
        //1. find near customer
        int near_customer_idx = FindNearCustomer();
        if (near_customer_idx == -1)
            break;

        //2. update board to delete curr customer
        start_pos = customers_start_pos[near_customer_idx];
        goal_pos = customers_goal_pos[near_customer_idx];
        board[start_pos.r][start_pos.c] = EMPTY;
        curr_dist = is_visited[start_pos.r][start_pos.c];
        amount_fuel -= curr_dist;

        //if the fuel is zero, fail
        if (amount_fuel <= 0)
            break;

        //3. move to destination
        if (MoveToDestination(start_pos, goal_pos))
        {
            ++total_customer;
            curr_dist = is_visited[goal_pos.r][goal_pos.c];
            amount_fuel += curr_dist * 2;
            taxi = goal_pos;
        }
        else
            break;
    }
    
    if (total_customer == M)
        cout << amount_fuel;
    else
        cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    Input();
    Solution();

    return 0;
}