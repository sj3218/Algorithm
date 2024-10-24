#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> trees;
    float count = 0;
    string tree;

    while (getline(cin, tree))
    {
        if (tree == "")
        {
            break;
        }
        trees[tree]++;
        count++;
    }

    cout << fixed;
    cout.precision(4);

    for (map<string, int>::iterator it = trees.begin(); it != trees.end(); ++it)
    {
        float percentage = it->second;
        percentage /= count;
        cout << it->first << " " << percentage*100 << "\n";
    }

    return 0;
}