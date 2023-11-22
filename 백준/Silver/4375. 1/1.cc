#include <iostream>

int main()
{
    int n;
    int k;
    int size;
    
    while(std::cin >> n)
    {
        k = 1;
        size = 1;
        while(k % n != 0)
        {
            ++size;
            k = (k* 10 + 1)%n;
        }
        
        std::cout<<size<<std::endl;
    }
    return 0;
}