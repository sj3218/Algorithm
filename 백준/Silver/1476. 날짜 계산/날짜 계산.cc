#include <iostream>

int main()
{
    int E, M, S;
    
    std::cin>>E >>M>>S;
    
    int result = 0;
    int mod_E, mod_M, mod_S;
    
    while(++result)
    {
        mod_E = (result-E) % 15;
        mod_M = (result-M) % 28;
        mod_S = (result-S) % 19;
        
        if(mod_E == 0 && mod_M == 0 && mod_S == 0)
        {
            break;
        }
    }
    
    std::cout<<result<<std::endl;
    return 0;
}