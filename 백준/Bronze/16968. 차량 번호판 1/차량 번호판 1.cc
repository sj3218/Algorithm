#include <iostream>
#include <string>

using namespace std;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> s;
    int size = s.size();
    int c_size = 26;
    int d_size = 10;
    
    int ans = 1;
    char c;
    char pre = ' ';

    for (int i = 0; i < size; ++i) 
    {
        c = s[i];
        if (c == 'c') 
        {
            if (c == pre)
            {
                ans *= c_size;
            }
            else
            {
                ans *= c_size--;
                d_size = 10;
            }
        }
        else
        {
            if (c == pre)
            {
                ans *= d_size;
            }
            else
            {
                ans *= d_size--;
                c_size = 26;
            }
        }
        pre = c;
    }

    cout << ans;


    return 0;
}