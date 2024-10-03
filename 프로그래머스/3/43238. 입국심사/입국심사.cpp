#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    int size = times.size();

    long long low = 0;
    long long high = 10e16;
    long long answer = high;
    long long mid;

    while (low <= high)
    {
        long long count = 0;

        for (int i = 0; i < size; ++i)
        {
            mid = low + (high - low) / 2;
            count += mid / times[i];

            if (count > n)
            {
                high = mid-1;
                break;
            }
        }

        if(count >= n)
        {
            high = mid -1;
            answer = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return answer;
}