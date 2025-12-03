#include <iostream>
#include <algorithm>
#include <tuple>
#include <string>
#include <vector>

using namespace std;

const int CHAR_SIZE = 'Z' - 'A'+1;
const int INF = 0x7fffffff;

void CountFrequency(vector<int> v[], string s)
{
    int size = s.size();
    int idx;
    for (int i = 0; i < size; ++i)
    {
        idx = s[i] - 'a';
        v[idx].push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int test_case;
    cin >> test_case;
    string s;
    int k;
    int size;
    int diff;
    while (test_case--)
    {
        cin >> s >>k;
        int min_length = INF;
        int max_length = 0;

        vector<int> freq_char[CHAR_SIZE];
        CountFrequency(freq_char, s);

        for (int i = 0; i < CHAR_SIZE; ++i)
        {
            size = freq_char[i].size();
            if (size >= k)
            {
                for (int j = k - 1; j < size; ++j)
                {
                    diff = freq_char[i][j] - freq_char[i][j - k + 1] + 1;
                    min_length = min(min_length, diff);
                    max_length = max(max_length, diff);
                }
            }
        }

        if (min_length == INF)
            cout << "-1\n";
        else
        {
            cout << min_length << " " << max_length << "\n";
        }
    }
    return 0;
}