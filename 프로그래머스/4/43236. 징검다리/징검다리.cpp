#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0; 
    
    std::sort(rocks.begin(), rocks.end());
    rocks.push_back(distance);
    
    int size = rocks.size();
    int begin = 1;
    int end = distance+1;
    int mid = 0;
    
    while(begin < end)
    {
        mid = (begin + end)/2;
        int prev = 0;
        int count = 0;
        int diff = 0;
        
        for(int i = 0; i< size; ++i)
        {
            diff = rocks[i] - prev;
            if(diff < mid)
            {
                ++count;
                continue;
            }
            
            prev = rocks[i];
        }
        
        if(count > n)
        {
            end = mid;
        }
        else
        {
            begin = mid + 1;
            answer = max(answer, mid);
        }
    }
    
    return answer;
}