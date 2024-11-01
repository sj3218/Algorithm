#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> is_visited;

bool DFS(string curr, vector<vector<string>> tickets, vector<string>& ans, int use_ticket)
{
    ans.push_back(curr);
    
    if(use_ticket == tickets.size())
        return true;
    
    for(int i = 0; i< tickets.size(); ++i)
    {
        if(tickets[i][0] == curr && is_visited[i] == false)
        {
            is_visited[i] = true;
            bool t = DFS(tickets[i][1], tickets, ans, use_ticket+1);
            
            if(t)
            {
                return true;
            }
            
            is_visited[i] = false;
        }
    }
    
    ans.pop_back();
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int size = tickets.size();
    is_visited.assign(size, false);
    
    sort(tickets.begin(), tickets.end());
    
    DFS("ICN", tickets, answer, 0);
    
    return answer;
}