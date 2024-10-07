#include <string>
#include <vector>

using namespace std;
vector<vector<int>> dp;

int recursive(vector<vector<int>> triangle, int height, int index, int sum)
{
    int left = triangle[height][index];
    int right = triangle[height][index + 1];
    
    if(triangle.size()- 1 == height)
    {
        if(left < right)
        {
            return sum + right;
        }
        else 
            return sum + left;
    }
    
    left = recursive(triangle, height + 1, index, sum + left);
    right = recursive(triangle, height + 1, index + 1, sum + right);
    
    if(left < right)
    {
        return right;
    }
    return left;
}

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = 0;
    int index = 0;
    
    dp.assign(triangle.size(), vector<int>(triangle.size(), 0));
    dp[0][0] = triangle[0][0];
    //answer = recursive(triangle, 1, 0, triangle[0][0]);
    
    int h_size = triangle.size();
    int n_size;
    int value = 0;
    int left, right;
    for(int i = 1; i< h_size; ++i)
    {
        n_size = triangle[i].size();
        for(int j = 0; j < n_size; ++j)
        {
            value = triangle[i][j];
            if(j - 1 < 0)
            {
                dp[i][j] = value + dp[i-1][j];
                answer = max(dp[i][j], answer);
                continue;
            }
            
            left = dp[i-1][j-1];
            right= dp[i-1][j];
            
            if(left < right)
            {
                dp[i][j] = value + right;
            }
            else
            {
                dp[i][j] = value + left;
            }
            
                answer = max(dp[i][j], answer);
        }
    }
    
    return answer;
}