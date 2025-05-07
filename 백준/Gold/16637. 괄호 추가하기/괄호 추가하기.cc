#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MINF 0x80000000

using namespace std;
int N;
string express;
int answer = MINF;

int calc(char op, int a, int b)
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }

    return a * b;
}

void dfs(int idx, int cur)
{
    if (idx >= N)
    {
        answer = max(answer, cur);
        return;
    }

    char op;
    if (idx == 0)
        op = '+';
    else
        op = express[idx - 1];

    if (idx + 2 < N)
    {
        int val = calc(express[idx + 1], express[idx] - '0', express[idx + 2] - '0');
        dfs(idx + 4, calc(op, cur, val));
    }

    dfs(idx + 2, calc(op, cur, express[idx] - '0'));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 

    cin >> N >> express;

    dfs(0, 0);
    cout << answer;

    return 0;
}