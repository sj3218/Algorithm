#include <iostream>
#include <algorithm>
#define DWARF 7

bool recursive(int* answer, int* heights, int& count, int& sum, int index)
{
    if (sum > 100)
    {
        return false;
    }

    if (count == 7)
    {
        if (sum == 100)
        {
            return true;
        }
        return false;
    }

    if (index >= 9)
    {
        return false;
    }

    sum += heights[index];
    answer[count] = heights[index];

    if (!recursive(answer, heights, ++count, sum, index + 1))
    {
        sum -= heights[index];
        
        return recursive(answer, heights, --count, sum, index + 1);
    }

    return true;
}

int main()
{
    int heights[9];
    int answer[7];
    int sum = 0;
    int count = 0;

    for (int i = 0; i < 9; ++i)
    {
        std::cin >> heights[i];
    }

    std::sort(heights, heights + 9);
    recursive(answer, heights, count, sum, 0);

    for (int i = 0; i < DWARF; ++i)
    {
        std::cout << answer[i] << std::endl;
    }

    
}