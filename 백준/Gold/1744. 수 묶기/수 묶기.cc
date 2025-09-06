#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;
#define INF 0X7FFFFFFF

int N;
vector<int> positive_nums;
vector<int> negative_nums;
vector<int> ones;
vector<int> zeros;
int prefix_multi[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        if (num > 1)
            positive_nums.push_back(num);
        else if (num == 1)
            ones.push_back(1);
        else if (num == 0)
            zeros.push_back(0);
        else
            negative_nums.push_back(num);
    }

    sort(positive_nums.begin(), positive_nums.end());
    sort(negative_nums.begin(), negative_nums.end());
    int answer = 0;
    
    int size = positive_nums.size();
    int j;
    for (int i = size - 2; i >= 0; i -= 2)
    {
        j = i + 1;
        answer += positive_nums[i] * positive_nums[j];
    }
    if (size % 2 != 0)
        answer += positive_nums[0];

    size = negative_nums.size();
    for (int i = 0; i < size - 1; i+=2)
    {
        j = i + 1;
        answer += negative_nums[i] * negative_nums[j];
    }

    if (size % 2 != 0)
    {
        if (zeros.size() == 0)
            answer += negative_nums[size - 1];
    }

    size = ones.size();
    answer += size;
    
    cout << answer;
    return 0;
}