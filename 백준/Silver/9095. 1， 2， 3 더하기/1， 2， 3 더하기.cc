#include <iostream>

int dp[11] = {1,2,4};
int main()
{
    int test_num;
    int num;
    
    for(int i = 3; i< 11; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    
    std::cin >> test_num;
    
    while(test_num--)
    {
        std::cin >> num;
        
        std::cout<< dp[num-1] <<std::endl;
        
    }
    
    return 0;
}