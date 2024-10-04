#include <string>
#include <vector>

using namespace std;

vector<bool> is_visited;

//dfs
bool dfs(int n, vector<vector<int>> computers, int curr_c)
{
    if(is_visited[curr_c])
    {
        return false;
    }
    
    is_visited[curr_c] = true;
    
    for(int i = 0; i < n; ++i)
    {
        if(curr_c == i)
        {
            continue;
        }
        
        if(computers[curr_c][i] == 0)
        {
            continue;
        }
        
        if(is_visited[i] == false)
        {
            if(!dfs(n, computers, i))
                continue;
        }
    }
    
    return true;
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    is_visited.assign(n,false);
    
    for(int i = 0; i< n; ++i)
    {
        if(dfs(n, computers, i))
        {
            ++answer;
        }
    }
    
    
    
    return answer;
}