#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<pair<int,int>> FindRoutes(vector<vector<int>> points, vector<int> route)
{
    vector<pair<int,int>> routes;
    
    int cr = points[route[0]-1][0];
    int cc = points[route[0]-1][1];
    int end_r, end_c;
    int size = route.size();
    routes.push_back({cr, cc});
    
    for(int i = 1; i < size; ++i)
    {
        end_r = points[route[i]-1][0];
        end_c = points[route[i]-1][1];
        //move r
        while(cr != end_r)
        {
            if(cr < end_r)
                ++cr;
            else
                --cr;
            routes.push_back({cr, cc});
        }
    
        //move c
        while(cc != end_c)
        {
            if(cc < end_c)
                ++cc;
            else
                --cc;
            routes.push_back({cr, cc});
        }
    }
    return routes;
}

int CountCollision(vector<vector<pair<int,int>>> opt_routes, int robot_cnt, int max_route_cnt)
{
    int total_danger = 0;
    int r, c;
    for(int i = 0; i< max_route_cnt; ++i)
    {
        unordered_map<int,int> cnt;
        for(int robot = 0; robot < robot_cnt ;++robot)
        {
            if(opt_routes[robot].size() <= i)
                continue;
            
            r = opt_routes[robot][i].first;
            c = opt_routes[robot][i].second;
            ++cnt[r * 1000 + c];
        }
        
        unordered_map<int,int>::iterator it;
        for(it = cnt.begin(); it!= cnt.end(); ++it)
        {
            if(it-> second >= 2)
                ++total_danger;
        }
    }
    
    return total_danger;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> opt_routes;
    int robot_cnt = routes.size();
    int max_route_cnt = 0;
    
    for(int i = 0; i<robot_cnt; ++i)
    {
        opt_routes.push_back(FindRoutes(points, routes[i]));
        max_route_cnt = max(max_route_cnt, (int)opt_routes[i].size());
    }
    
    answer = CountCollision(opt_routes, robot_cnt, max_route_cnt);
    
    return answer;
}