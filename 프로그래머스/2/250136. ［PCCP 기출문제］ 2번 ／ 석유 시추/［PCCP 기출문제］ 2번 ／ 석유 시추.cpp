#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool is_visited[501][501];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int count_oil[250001];//by index
bool oil_visited[250001];

bool OutOfBound(int r, int c, int R, int C)
{
    if(r < 0 || c < 0 || r >= R || c >= C)
        return true;
    return false;
}

void bfs(int r, int c, vector<vector<int>> &board, int R, int C, int idx)
{
    queue<pair<int,int>> q;
    q.push({r, c});
    is_visited[r][c] = true;
    int cnt = 1;
    
    int nr, nc;
    while(!q.empty())
    {
        tie(r, c) = q.front(); q.pop();
        board[r][c] = idx;
        
        for(int i = 0; i< 4; ++i)
        {
            nr = r + dr[i];
            nc = c + dc[i];
            
            if(OutOfBound(nr,nc, R, C) || board[nr][nc] == 0)
                continue;
            
            if(is_visited[nr][nc])
                continue;
            
            is_visited[nr][nc] = true;
            q.push({nr,nc});
            cnt++;
        }
    }
    
    count_oil[idx] = cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int R = land.size();
    int C = land[0].size();
    int idx = 2;
    
    for(int r = 0; r < R; ++r)
    {
        for(int c = 0; c<C; ++c)
        {
            if(is_visited[r][c] || land[r][c] == 0)
                continue;
            bfs(r,c,land, R, C, idx);
            ++idx;
        }
    }
    
    int cnt;
    for(int c = 0; c < C; ++c)
    {
        cnt = 0;
        fill_n(oil_visited, 250001, false);
        
        for(int r = 0; r < R; ++r)
        {
            idx = land[r][c];
            if(idx >= 2 && !oil_visited[idx])
            {
                oil_visited[idx]= true;
                cnt += count_oil[idx];
            }
        }
        if(answer < cnt)
            answer = cnt;
    }
    return answer;
}