#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A, B;
int arr1[500001];
int arr2[500001];

bool binarysearch(int target)
{
    int start = 0;
    int end = B - 1;

    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr2[mid] < target)
        {
            start = mid + 1;
        }
        else if (arr2[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            return true;
        }
    }

    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> A >> B;

    for (int i = 0; i < A; ++i)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < B; ++i)
    {
        cin >> arr2[i];
    }

    sort(arr1, arr1+A);
    sort(arr2, arr2+B);
    vector<int> answer;
    for (int i = 0; i < A; ++i)
    {
        if (!binarysearch(arr1[i]))
        {
            answer.push_back(arr1[i]);
        }
    }
    
    cout << answer.size()<<"\n";
    for (int i = 0; i < answer.size(); ++i)
    {
        cout << answer[i]<<" ";
    }
    return 0;
}