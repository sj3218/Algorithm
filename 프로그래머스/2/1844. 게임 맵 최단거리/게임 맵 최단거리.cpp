#include<vector>
#include <queue>
using namespace std;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<vector<bool>> is_visited;
vector<vector<int>> sum;

bool dfs(vector<vector<int>>maps, int x, int y, int& count)
{
    //out of maps
    if( x< 0 || y< 0 || x>= maps.size() || y>= maps[0].size())
    {
        return false;
    }
    
    //if current point is visited
    if(is_visited[x][y] == true)
    {
        return false;
    }
    
    //if current point is on the wall
    if(maps[x][y] == 0)
    {
        return false;
    } 
    
    is_visited[x][y] = true;
    
    for(int i = 0; i< 4; ++i)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        count += 1;
        
        if(dfs(maps, next_x, next_y, count))
        {
            return true;
        }
        
        count -= 1;
    }
    
    if(x == maps.size() -1 && y == maps[0].size() -1)
    {
        return true;
    }
    
    return false;
}


int solution(vector<vector<int> > maps)
{
    int answer = -1;
    is_visited.assign(maps.size(), vector<bool>(maps[0].size(), false));
    sum.assign(maps.size(), vector<int>(maps[0].size(), 0));
    
    /*
    if(!dfs(maps, 0, 0, answer))
    {
        return -1;
    }*/
    
    int size_x = maps.size();
    int size_y = maps[0].size();
    
    //bfs 
    queue<pair<int,int>> q;
    q.push({0,0});
    is_visited[0][0] = true;
    sum[0][0] = 1;
    
    while(!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int i = 0; i< 4; ++i)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx < 0 || size_x <= nx || ny < 0|| size_y <= ny)
            {
                continue;
            }
            
            if(maps[nx][ny] == 1 && is_visited[nx][ny] == false)
            {
                if(sum[nx][ny] == 0 || sum[nx][ny] < sum[cx][cy] + 1)
                {
                    q.push({nx,ny});
                    is_visited[nx][ny] = true;
                    sum[nx][ny] = sum[cx][cy] + 1;
                }
            }
        }
    }
    
    if(sum[size_x -1][size_y -1] != 0)
    {
        return sum[size_x -1][size_y -1];
    }
    
    return answer;
}