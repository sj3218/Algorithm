#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    int end = *std::max_element(stones.begin(), stones.end());
    int begin = *std::min_element(stones.begin(), stones.end());
    int count_k = 0;
    int stones_size = stones.size();
    int mid = 0;

    while (begin <= end)
    {
        mid = (begin + end) / 2;
        count_k = 0;

        for (int i = 0; i < stones_size; ++i)
        {
            if (stones[i]- mid < 0)
            {
                ++count_k;
                if (count_k == k)
                {
                    break;
                }
            }
            else
            {
                count_k = 0;
            }
        }

        if (count_k < k)
        {
            answer = max(mid, begin);
            begin = mid+1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return answer;
}