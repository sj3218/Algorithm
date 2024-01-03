#include <iostream>

bool IsDecimal(int num)
{
    if(num == 1)
    {
        return false;
    }
    
    for(int i = 2; i< num; ++i)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    int size, num;
    
    std::cin >> size;
    
    int ans = 0;
    
    for(int i = 0 ; i< size; ++i)
    {
        std::cin >> num;
        
        if(IsDecimal(num))
        {
            ++ans;
        }
    }
    
    std::cout << ans;
    return 0;
}