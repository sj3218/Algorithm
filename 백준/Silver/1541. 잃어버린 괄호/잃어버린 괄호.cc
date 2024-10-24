#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    string num;
    int ans = 0;
    
    bool is_minus = false;
    
    cin >> s;
    int size = s.size();
    
    for(int i = 0; i<= size; ++i)
    {
        if(s[i] == '+' || s[i] == '-' || s[i] == '\0')
        {
            if(is_minus)
            {
                ans -= stoi(num);
            }
            else
            {
                if(s[i] == '-')
                {
                    is_minus = true;
                }
                ans += stoi(num);
            }
            num = "";
        }
        else
        {
            num += s[i];
        }
    }
    
    cout << ans;
    return 0;
}