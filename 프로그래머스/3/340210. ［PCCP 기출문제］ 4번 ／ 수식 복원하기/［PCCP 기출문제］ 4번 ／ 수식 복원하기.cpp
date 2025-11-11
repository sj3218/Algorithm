#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct Expression
{
    string a;
    string b;
    string c;
    string oper;
};

Expression Split(string expression)
{
    vector<string> answer;
    stringstream ss(expression);
    string token;
    while (ss >> token)
    {
        answer.push_back(token);
    }
    Expression ex;
    ex.a = answer[0];
    ex.b = answer[2];
    ex.c = answer[4];
    ex.oper = answer[1];

    return ex;
}

string ToBase(int num, int base)
{
    if (num == 0)
        return "0";

    string answer;
    vector<char> temp;
    int digit;
    while (num > 0)
    {
        digit = num % base;
        temp.push_back('0' + digit);
        num /= base;
    }
    int size = temp.size();
    for (int i = size - 1; i >= 0; --i)
    {
        answer += temp[i];
    }
    return answer;
}

bool InValid(string s, int base)
{
    for (char c : s)
    {
        if (c >= '0' + base)
            return false;

    }
    return true;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<Expression> has_X;
    vector<int> bases;
    for (int i = 2; i <= 9; ++i)
        bases.push_back(i);

    int size = expressions.size();
    for (int i = 0; i < size; ++i)
    {
        Expression ex = Split(expressions[i]);
        if (ex.c == "X")
        {
            has_X.push_back(ex);
            vector<int> new_bases;
            for (int base : bases)
            {
                if (!InValid(ex.a, base) || !InValid(ex.b, base))
                    continue;
                new_bases.push_back(base);
            }
            bases = new_bases;
        }
        else
        {
            vector<int> new_bases;
            for (int base : bases)
            {
                if (!InValid(ex.a, base) || !InValid(ex.b, base) || !InValid(ex.c, base))
                {
                    continue;
                }
                int x = stoi(ex.a, nullptr, base);
                int y = stoi(ex.b, nullptr, base);
                int z = stoi(ex.c, nullptr, base);
                if ((ex.oper == "+" && (x + y == z)) || (ex.oper == "-" && (x - y == z)))
                {
                    new_bases.push_back(base);
                }
            }
            bases = new_bases;
        }
    }


    for (Expression ex : has_X)
    {
        set<string> results;
        for (int base : bases)
        {
            int x = stoi(ex.a, nullptr, base);
            int y = stoi(ex.b, nullptr, base);
            int res;
            if (ex.oper == "+")
            {
                res = x + y;
            }
            else
                res = x - y;
            results.insert(ToBase(res, base));
        }
        string ans;
        ans = ex.a + " " + ex.oper + " " + ex.b + " = ";
        if (results.size() == 1)
            ans += *results.begin();
        else
            ans += "?";

        answer.push_back(ans);

    }
    return answer;
}
