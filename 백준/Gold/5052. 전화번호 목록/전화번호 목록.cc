#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int T, cnt;
    cin >> T;
    
    for(int t = 0; t < T; ++t)
    {
        vector<string> numbers;
        map<string, int> book;
        
        cin >> cnt;
        
        for(int i = 0; i< cnt; ++i)
        {
            string num;
            cin >> num;
            numbers.push_back(num);
            book[num] = 1;
        }
        
        bool ans = true;
        for(int i = 0; i< cnt; ++i)
        {
            int size = numbers[i].size();
            string tmp = "";
            
            for(int j = 0; j< size; ++j)
            {
                tmp += numbers[i][j];
                if(tmp == numbers[i])
                    continue;
                
                if(book.find(tmp) != book.end())
                {
                    ans = false;
                    break;
                }
            }
        }
        
        if(ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout <<"NO\n";
        }
    }
    return 0;
}