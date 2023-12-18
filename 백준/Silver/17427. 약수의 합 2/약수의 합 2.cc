	#include <iostream>
using namespace std;
 
int main(){
    
    
    int N;
    long long ans=0;
    cin >> N;
    
    for(int i = 1; i<=N; i++){
        ans += (N/i)* i;
    }
    
    cout << ans << "\n";
    
    return 0;
}