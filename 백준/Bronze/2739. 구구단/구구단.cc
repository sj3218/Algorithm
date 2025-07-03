#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int a;
    cin >> a;
    for(int i = 1; i<=9; ++i)
    {
        cout << a <<" * " << i <<" = "<< a*i<<"\n";
    }
    return 0;
}