#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string a, b;
    cin >> a >> b;

    int hh = 0;
    int mm = 0;
    int ss = 0;
    int length = a.length();

    ss = ((b[6] - '0') * 10 + (b[7] - '0')) - ((a[6] - '0') * 10 + (a[7] - '0'));
    if (ss < 0)
    {
        ss += 60;
        mm -= 1;
    }

    mm += ((b[3] - '0') * 10 + (b[4] - '0')) - ((a[3] - '0') * 10 + (a[4] - '0'));
    if (mm < 0)
    {
        mm += 60;
        hh -= 1;
    }

    hh += ((b[0] - '0') * 10 + (b[1] - '0')) - ((a[0] - '0') * 10 + (a[1] - '0'));
    if (hh < 0)
    {
        hh += 24;
    }

    if (hh == 0 && mm == 0 && ss == 0)
    {
        cout << "24:00:00";
        return 0;
    }

    if (hh < 10)
    {
        cout << "0" << hh << ":";
    }
    else
    {
        cout << hh << ":";
    }
    if (mm < 10)
    {
        cout << "0" << mm << ":";
    }
    else
    {
        cout << mm << ":";
    }

    if (ss < 10)
    {
        cout << "0" << ss;
    }
    else
    {
        cout << ss;
    }



    return 0;
}