#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N;
char lc[27];
char rc[27];

void inorder(char i)
{
    cout << i;
    if (lc[i - 'A' + 1] != 0)
        inorder(lc[i - 'A' + 1]);
    if (rc[i - 'A' + 1] != 0)
        inorder(rc[i - 'A' + 1]);
}

void preorder(char i)
{
    if (lc[i - 'A' + 1] != 0)
        preorder(lc[i - 'A' + 1]);

    cout << i;

    if (rc[i - 'A' + 1] != 0)
        preorder(rc[i - 'A' + 1]);
}

void postorder(char i)
{
    if (lc[i - 'A' + 1] != 0)
        postorder(lc[i - 'A' + 1]);

    if (rc[i - 'A' + 1] != 0)
        postorder(rc[i - 'A' + 1]);

    cout << i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        char c, l, r;
        cin >> c >> l >> r;

        if(l != '.')
            lc[c - 'A' + 1] = l;

        if(r != '.')
            rc[c - 'A' + 1] = r;
    }

    inorder('A'); cout << "\n";
    preorder('A'); cout << "\n";
    postorder('A');
    return 0;
}