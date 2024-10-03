#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int target, int index, int sum)
{
    if(index == numbers.size())
    {
        if(target == sum)
        {
            return 1;
        }
        else
            return 0;
    }
    
    int count = dfs(numbers, target, index + 1, sum + numbers[index]);
    
    count += dfs(numbers, target, index + 1, sum - numbers[index]);
    
    return count;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = dfs(numbers, target, 0, 0);
    return answer;
}