#include <iostream>
#include <climits>

int main()
{
    int count;
    int num;
    int smallest = INT_MAX;
    int largest = INT_MIN;
    
    std::cin >> count;
    
    while(std::cin >> num)
    {
        if(num < smallest)
        {
            smallest = num;
        }
        if(num > largest)
        {
            largest = num;
        }
    }
    
    std::cout<<smallest*largest<<std::endl;
    
    return 0;
}