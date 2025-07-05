#include <iostream>
#include <algorithm>
using namespace std;

#define DIVIDE 1000
int N;
long long B;
int base[6][6];
int answer[6][6];
int temp[6][6];

// a = a * b
void multiply_matrix(int (*a)[6], int (*b)[6])
{
    int sum = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1 ; j <= N; ++j)
        {
            sum = 0;
            for (int k = 1; k <= N; ++k)
            {
                sum += a[i][k] * b[k][j];
            }
            temp[i][j] = sum % DIVIDE;
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            a[i][j] = temp[i][j];
        }
    }
}

void solution()
{
    long long exp = B;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            multiply_matrix(answer, base);
        }

        multiply_matrix(base, base);

        exp /= 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> B;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> base[i][j];
            if (i == j)
            {
                answer[i][j] = 1;
            }
        }
    }


    solution();

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}