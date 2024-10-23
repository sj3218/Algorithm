#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool win_sk = false;
    
    //짝수면 창영
    //홀수면 상근
    if(n % 2)
    {
        cout << "SK";
    }
    else 
    {
        cout <<"CY";
    }
    /*
    int left = n % 3;
    int div = n/ 3;
    
    if(left == 0)
    {
        if(div % 2)
        {
            win_sk = true;
        }
        else     
            win_sk = false;
    }
    else
    {
        if(div % 2)
        {
            
        }
    }*/
    
    return 0;
}