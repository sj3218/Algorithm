#include <iostream>
using namespace std;

int fib[21];
int n;

int main()
{
    cin >> n;
    fib[0] = 0;
    fib[1] = 1;
    
    for(int i = 2;i <= n; ++i)
    {
        fib[i] = fib[i-1] + fib[i-2];    
    }
    
    cout << fib[n];
    return 0;
}