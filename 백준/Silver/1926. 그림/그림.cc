#include <iostream>
#include <queue>

using namespace std;

int N, M;
int painting[501][501];
int is_visited[501][501];
int cnt_paintings = 0;
int max_area = 0;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool IsValid(int x, int y)
{
    if(x < 0 || y < 0 || x>= N || y >= M)
    {
        return false;
    }
    
    return true;
}

void bfs(int X, int Y)
{
    if(painting[X][Y] == 0)
        return;
    
    if(is_visited[X][Y] > 0)
        return; 
    
    cnt_paintings++;
    is_visited[X][Y] = cnt_paintings;
    int curr_area = 1;
    
    queue<pair<int,int>> q;
    q.push({X, Y});
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!IsValid(nx, ny) || is_visited[nx][ny] > 0)
                continue;
            
            if(painting[nx][ny] == 1)
            {
                is_visited[nx][ny] = cnt_paintings;
                q.push({nx, ny});
                curr_area++;
            }
        }
    }
    
    max_area = max(max_area, curr_area);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
    
    for(int i = 0; i< N; ++i)
    {
        for(int j = 0; j< M; ++j)
        {
            cin >> painting[i][j];
        }
    }
    
    for(int i = 0; i< N; ++i)
    {
        for(int j = 0; j< M; ++j)
        {
            bfs(i, j);
        }
    }
    
    cout << cnt_paintings <<"\n" << max_area;
    
    return 0;
}
