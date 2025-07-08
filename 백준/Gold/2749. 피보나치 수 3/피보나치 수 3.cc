#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

#define DIVIDE 1000000
long long N;
typedef vector<vector<long long>> Matrix;

Matrix multiply_matrix(Matrix& a, Matrix& b)
{
    Matrix result(2, vector<long long>(2));

    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= DIVIDE;
            }
        }
    }

    return result;
}

Matrix power_matrix(Matrix base, long long exp)
{
    Matrix result = { {1,0},{0,1} };
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = multiply_matrix(base, result);
        }
        base = multiply_matrix(base, base);
        exp /= 2;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;

    Matrix base = { {1,1},{1,0} };
    Matrix result = power_matrix(base, N-1);

    cout << result[0][0];

    return 0;
}