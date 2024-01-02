#include <iostream>

int main()
{
    int a,b;
    std::cin>>a >>b;
    int gcd = 1;
    int lcm = 1;
    int i = 2;
    
    while(a >= i && b >= i)
    {
        if(a % i == 0 && b % i == 0)
        {
            a /= i;
            b /= i;
            gcd *= i;
            i = 2;
        }
        else
        {
            ++i;
        }
    }
    
    std::cout << gcd<<std::endl;
    lcm = a * b * gcd;
    std::cout << lcm<<std::endl;
    return 0;
}