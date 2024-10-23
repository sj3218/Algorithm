#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
int N, M;
string dp[101][101];

int main()
{    
    cin >> N >> M;
    
    for(int i =1; i<= N; ++i)
    {
        for(int j = 0; j<= i; ++j)
        {
            if(j == 0 || j == i)
            {
                dp[i][j] = "1";
            }
            else
            {
                int sum = 0;
                string n1 = dp[i-1][j];
                string n2 = dp[i-1][j-1];
                
                while(!n1.empty() || !n2.empty() || sum)
                {
                    if(!n1.empty())
                    {
                        sum += n1.back() - '0';
                        n1.pop_back();
                    }
                    if(!n2.empty())
                    {
                        sum += n2.back() - '0';
                        n2.pop_back();
                    }
                    
                    dp[i][j].push_back((sum%10) + '0');
                    sum /= 10;
                }
                
                reverse(dp[i][j].begin(), dp[i][j].end());
            }
        }  
    }
    cout << dp[N][M];
    return 0;
}