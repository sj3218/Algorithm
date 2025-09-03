#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> dots) {
    int answer = 0;
    
    int min_x = dots[0][0];
    int max_x = min_x;
    int min_y = dots[0][1];
    int max_y = min_y;
    
    int x, y;
    for(int i = 1; i< 4; ++i)
    {
        x = dots[i][0];
        y = dots[i][1];
        min_x = min(min_x, x);
        min_y = min(min_y, y);
        max_x = max(max_x, x);
        max_y = max(max_y, y);
    }
    
    answer = (max_x - min_x) * (max_y - min_y);
    return answer;
}