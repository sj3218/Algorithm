#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<bool> flag) {
    vector<int> answer;
    int arr_size = arr.size();
    
    int cnt, value;
    for(int i = 0; i< arr_size; ++i)
    {
        value = arr[i];
        if(flag[i])
        {
            cnt = value * 2;
            answer.insert(answer.end(), cnt, value);
        }
        else
        {
            for(int j = 0; j< value; ++j)
            {
                answer.pop_back();
            }
        }
    }
    return answer;
}