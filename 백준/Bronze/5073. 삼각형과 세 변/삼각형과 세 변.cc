#include <iostream>

using namespace std;

const string EQUILATERAL = "Equilateral\n";
const string SCALENE = "Scalene\n";
const string ISOSCELES = "Isosceles\n";
const string INVALID = "Invalid\n";

bool CanMakeTriangle(int a, int b, int c)
{
    if (b < a && c < a)
    {
        if (a >= b + c)
            return false;
    }
    else if (a < b && c < b)
    {
        if (b >= a + c)
            return false;
    }
    else if (a < c && b < c)
    {
        if (c >= a + b)

            return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c;

    while (true)
    {
        cin >> a >> b >> c;
        if (a == 0)
            break;

        if (CanMakeTriangle(a, b, c))
        {
            if (a == b && b == c)
            {
                cout << EQUILATERAL;
                continue;
            }

            if (a != b && b != c && c != a)
            {
                cout << SCALENE;
                continue;
            }

            cout << ISOSCELES;

        }
        else
            cout << INVALID;
    }

    return 0;
}