#include <iostream>
#include <string>
#include <vector>

using namespace std;

int to_seconds(int h, int m, int s)
{
    return h*3600 + m * 60 + s;
}

vector<double> to_degree(int t)
{
    vector<double> d(3);
    int h = t/3600;
    int m = (t%3600) / 60;
    int s = (t % 3600) % 60;
    d[0] = (h%12)*30.0 + m * 0.5 + s * (1/120.0);
    d[1] = m * 6.0 + s * 0.1;    
    d[2] = s * 6.0;    
    return d;
}

bool HourMatch(vector<double> c, vector<double> n)
{
    if(c[0] > c[2] && n[0] <= n[2])
        return true;
    
    if(c[2] == 354 && c[0] >354)
        return true;
    
    return false;
}

bool MinMatch(vector<double> c, vector<double> n)
{
    if(c[1] > c[2] && n[1] <= n[2])
        return true;
    
    if(c[1] > 354 && c[2] == 354)
        return true;
    
    return false;
}

int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    int start = to_seconds(h1,m1,s1);
    int end = to_seconds(h2,m2,s2);
    
    vector<double> curr= to_degree(start);
    vector<double> next; 
    bool m_match, h_match;
    for(int i = start; i< end;++i)
    {
        next = to_degree(i+1);
        m_match = MinMatch(curr, next);
        h_match = HourMatch(curr, next);
        if(h_match)
        {
            ++answer;
            if(m_match && next[1] != next[0])
            {
                ++answer;
            }
        }
        else if(m_match)
        {
            ++answer;
        }
        curr = next;
    }
    
    //12:0:0 -> 12*3600
    if(start == 0 || start == 43200)
        ++answer;
    return answer;
}