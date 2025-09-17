#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;
#define INF 0X7FFFFFFF

int N;
int inorder[100001];
int postorder[100001];

void solve(int in_s, int in_e, int post_s, int post_e)
{
    if (in_s > in_e || post_s > post_e)
        return;
    cout << postorder[post_e] << " ";

    int root = find(inorder, inorder + N, postorder[post_e]) - inorder;
    int size = root - in_s;
    solve(in_s, root - 1, post_s, post_s + size - 1);
    solve(root + 1, in_e, post_s + size, post_e - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> inorder[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        cin >> postorder[i];
    }

    solve(1, N, 1, N);

    return 0;
}