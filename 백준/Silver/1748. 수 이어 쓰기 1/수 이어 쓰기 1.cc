#include <iostream>

int main()
{
    int num;
    std::cin >> num;
    int result = 0;

    for (int i = 1; i <= num; i *= 10)
    {
        result += num - i + 1;
    }
    std::cout << result;

    return 0;
}