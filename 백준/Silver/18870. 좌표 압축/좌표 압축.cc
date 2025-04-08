#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[1000001];
int temp[1000001];
vector<int> uni;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i = 0; i< N; ++i)
    {
        cin >> arr[i];
        temp[i] = arr[i];
    }
    sort(temp, temp+N);
    
    uni.push_back(temp[0]);
    for(int i = 1; i< N; ++i)
    {
        if(temp[i-1] != temp[i])
            uni.push_back(temp[i]);
    }
    
    for(int i = 0; i< N; ++i)
    {
        cout << lower_bound(uni.begin(), uni.end(), arr[i]) - uni.begin() <<" ";
    }
    return 0;
}