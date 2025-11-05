#include <iostream>
#include <string>
#include <vector>

using namespace std;

int change_time_to_int(string time_)
{
    int pos = time_.find(':');
    string min = time_.substr(0, pos);
    string sec = time_.substr(pos+1);
    
    return stoi(min) * 60 + stoi(sec);
}

string change_int_to_time(int time_)
{
    string t;
    
    int min, sec;
    min = time_ / 60;
    sec = time_ % 60;
    cout << min << " "<<sec;
    if(min < 10)
        t += "0";
    
    t += to_string(min);
    t += ":";
    
    if(sec < 10)
        t += "0";
    t += to_string(sec);
    
    return t;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    int size = commands.size();
    int curr, op_s, op_e, vid_end;
    op_s = change_time_to_int(op_start);
    op_e = change_time_to_int(op_end);
    curr = change_time_to_int(pos);
    vid_end = change_time_to_int(video_len);

    if(op_s <= curr && curr <= op_e)
        curr = op_e;
    
    for(int i = 0; i< size; ++i)
    {
        if(commands[i] == "next")
        {
            curr += 10;
        }
        else
        {
            curr -= 10;
        }
        
        if(curr < 0)
            curr = 0;
        if(op_s <= curr && curr <= op_e)
            curr = op_e;
        if(curr > vid_end)
            curr = vid_end;
    }
    
    answer = change_int_to_time(curr);
    return answer;
}