#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

#define CARD_SIZE 62
using namespace std;

struct Range
{
    int sr, sc;
    int er, ec;
};

int N, M;
char board[51][51];                 //board information
bool is_existed[CARD_SIZE];         //existed cards in board
Range ranges[CARD_SIZE];            //range of cards(size)
int card_cnt = 0;                   //total existed cards in board
bool success = true;
bool cards[CARD_SIZE][CARD_SIZE];   //information of connected cards
int degrees[CARD_SIZE];             //
string answer;

int ConvertCharToInt(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A' + 10;
    }

    if ('a' <= c && c <= 'z')
    {
        return c - 'a' + 36;
    }

    return c - '0';
}

char ConvertIntToChar(int num)
{
    if (10 <= num && num <= 35)
    {
        return num + 'A' - 10;
    }

    if (36 <= num && num <= 61)
    {
        return num + 'a' - 36;
    }

    return num + '0';
}

void FindCardRange()
{
    for (int i = 0; i < CARD_SIZE; ++i)
    {
        ranges[i] = { 0x7fffffff, 0x7fffffff, 0,0 };
    }

    for (int r = 0; r < N; ++r)
    {
        for (int c = 0; c < M; ++c)
        {
            if (board[r][c] == '.')
                continue;

            int num = ConvertCharToInt(board[r][c]);

            if (is_existed[num] == false)
            {
                is_existed[num] = true;
                ++card_cnt;
            }

            ranges[num].sr = min(ranges[num].sr, r);
            ranges[num].sc = min(ranges[num].sc, c);
            ranges[num].er = max(ranges[num].er, r);
            ranges[num].ec = max(ranges[num].ec, c);
        }
    }
}

void FindConnectedCard()
{
    for (int i = 0; i < CARD_SIZE; ++i)
    {
        if (!is_existed[i])
            continue;

        for (int r = ranges[i].sr; r <= ranges[i].er; ++r)
        {
            for (int c = ranges[i].sc; c <= ranges[i].ec; ++c)
            {
                char curr = board[r][c];

                if (curr == ConvertIntToChar(i))
                    continue;

                if (curr == '.')
                {
                    success = false;
                    return;
                }

                int num = ConvertCharToInt(curr);

                if (!cards[i][num])
                {
                    cards[i][num] = true;
                    degrees[num] += 1;
                }
            }
        }
    }
}

void FindAnswer()
{
    if (!success)
        return;

    priority_queue<int, vector<int>, greater<int>> pq;
    int visited_cnt = 0;

    for (int i = 0; i < CARD_SIZE; ++i)
    {
        if (is_existed[i] && degrees[i] == 0)
        {
            pq.push(i);
        }
    }

    int curr = 0;
    while (!pq.empty())
    {
        curr = pq.top();
        pq.pop();

        visited_cnt++;
        answer += ConvertIntToChar(curr);

        for (int i = 0; i < CARD_SIZE; ++i)
        {
            if (!cards[curr][i])
                continue;
            
            cards[curr][i] = false;
            degrees[i]--;

            if (degrees[i] == 0)
                pq.push(i);
        }
    }

    if (visited_cnt != card_cnt)
    {
        success = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
    }

    FindCardRange();
    FindConnectedCard();
    FindAnswer();

    if (success)
    {
        cout << answer;
    }
    else
    {
        cout << "-1";
    }

    return 0;
}