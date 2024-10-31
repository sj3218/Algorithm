#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> arr;
    long long sum = 0;
    int val;
    for(int i = 0; i< n;++i)
    {
        cin >> val;
        sum += val;
        arr.push_back(val);
    }
    
    long long ans = 0;
    for(int i = 0; i< n; ++i)
    {
        sum -= arr[i];
        ans += sum * arr[i];
    }
    
    cout << ans;
    return 0;
}