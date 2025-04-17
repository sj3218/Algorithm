#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 4000001

using namespace std;

int N;
vector<int> prime;
int is_prime[SIZE];

void FindPrime()
{
    fill_n(is_prime, SIZE, true);

    for (int i = 2; i < SIZE; ++i)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
        }

        for (int j = 2; j * i < SIZE; ++j)
        {
            is_prime[j*i] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    FindPrime();

    int start = 0;
    int end = 0;
    int sum = prime[0];
    int answer = 0;
    int size = prime.size();
    while (start < size && end < size && start <= end)
    {
        if (sum == N)
        {
            ++answer;
        }

        if (sum <= N)
        {
            ++end;
            sum += prime[end];
        }
        else
        {
            sum -= prime[start];
            ++start;
        }
    }

    cout << answer;
    return 0;
}