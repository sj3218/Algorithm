#include <string>
#include <vector>

using namespace std;

void hanoi(int n, int start, int end, int sub, vector<vector<int>>& ans)
{
    if(n == 1)
    {
        //move the block from start to end
        ans.push_back({start, end});
        return;
    }
    
    hanoi(n-1, start, sub, end, ans);
    
    //move the last block from start to end
    ans.push_back({start, end});
    
    hanoi(n-1, sub, end, start, ans);
    
    return;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    
    hanoi(n, 1, 3, 2, answer);
    
    return answer;
}