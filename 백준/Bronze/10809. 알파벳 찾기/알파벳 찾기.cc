#include <iostream>
#include <string>
#include <algorithm>

#define SIZE 'z' - 'a'+1

using namespace std;

int dp[SIZE];
string s;

int main()
{
    cin >> s;    
    int size = s.size();
    fill_n(dp, SIZE, -1);
    
    for(int i = 0; i< size; ++i)
    {
        int index = s[i] - 'a';
        
        if(dp[index] == -1)
        {
            dp[index] = i;
        }
    }
    
    for(int i = 0; i< SIZE; ++i)
    {
        cout << dp[i]<<" ";
    }
    
    return 0;
}