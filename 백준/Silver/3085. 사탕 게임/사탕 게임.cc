#include <iostream>
#include <algorithm>

std::string candy[50];
int size = 0;

int NumberOfCandy()
{
    int result = 1;
    int temp = 1;

    //count row
    for (int i = 0; i < size; ++i)
    {
        temp = 1;
        for (int j = 1; j < size; ++j)
        {
            if (candy[i][j] == candy[i][j -1])
            {
                ++temp;
            }
            else
            {
                result = std::max(temp, result);
                temp = 1;
            }

        }
        result = std::max(temp, result);
    }

    //count column
    for (int i = 0; i < size; ++i)
    {
        temp = 1;
        for (int j = 1; j < size; ++j)
        {
            if (candy[j][i] == candy[j -1][i])
            {
                ++temp;
            }
            else
            {
                result = std::max(temp, result);
                temp = 1;
            }
        }
        result = std::max(temp, result);
    }

    return result;
}

int main()
{
    int result = 0;

    std::cin >> size;

    for (int i = 0; i < size; ++i)
    {
        std::cin >> candy[i];
    }

    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j < size; ++j)
        {
            std::swap(candy[i][j], candy[i][j - 1]);
            result = std::max(result, NumberOfCandy());
            std::swap(candy[i][j], candy[i][j - 1]);

            std::swap(candy[j][i], candy[j - 1][i]);
            result = std::max(result, NumberOfCandy());
            std::swap(candy[j][i], candy[j - 1][i]);
        }
    }

    std::cout << result;
}
