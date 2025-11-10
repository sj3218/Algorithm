#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0x7fffffff;
    
    int size = diffs.size();
    
    int start = 1;
    int end = *max_element(diffs.begin(), diffs.end());
    int mid;
    long long curr_time;
    while(start <= end)
    {
        mid = (start + end)/2;
        curr_time = 0;
        
        for(int i = 0; i< size; ++i)
        {
            curr_time += times[i];
            
            if(diffs[i] > mid)
            {
                if(i == 0)
                    curr_time += (diffs[i] - mid) * times[i];
                else
                    curr_time += (diffs[i] - mid) * (times[i] + times[i-1]);
            }
        }
        
        //cout << curr_time <<", "<< start <<", " << end<<"\n";
        if(curr_time <= limit)
        {
            end = mid - 1;
            answer = min(answer, mid);
        }
        else
        {
            start = mid + 1;
        }
    }
    
    return answer;
}