#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k) {
    int answer = 0;
    
    int row = board.size();
    int col = board[0].size();
    
    for(int r = 0; r < row; ++r)
    {
        for(int c = 0; c < col; ++c)
        {
            if(r + c > k)
                break;
            
            answer += board[r][c];
        }
    }
    return answer;
}