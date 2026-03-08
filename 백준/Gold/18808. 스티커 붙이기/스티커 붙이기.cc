#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <stack>

using namespace std;

int width, height, sticker_cnt;

bool stickers[101][11][11];
pair<int, int> stickers_rc[101];
int stickers_area_cnt[101];
bool temp_sticker[11][11];

bool board[41][41];

void Input()
{
    cin >> height >> width >> sticker_cnt;
    
    int r, c;
    int value;
    for (int i = 0; i < sticker_cnt; ++i)
    {
        cin >> r >> c;
        stickers_rc[i] = { r,c };
        for (int x = 0; x < r; ++x)
        {
            for (int y = 0; y < c; ++y)
            {
                cin >> value;
                if (value == 0)
                {
                    stickers[i][x][y] = false;
                }
                else
                {
                    stickers[i][x][y] = true;
                    ++stickers_area_cnt[i];
                }
            }
        }
    }
}


bool AttachSticker(int start_r, int start_c, int idx)
{
    int r, c;
    tie(r, c) = stickers_rc[idx];
    r += start_r;
    c += start_c;

    for (int x = start_r; x < r; ++x)
    {
        for (int y = start_c; y < c; ++y)
        {
            if (!stickers[idx][x-start_r][y-start_c])
                continue;
            else
            {
                if (board[x][y])
                {
                    return false;
                }
            }
        }
    }

    for (int x = start_r; x < r; ++x)
    {
        for (int y = start_c; y < c; ++y)
        {
            if (stickers[idx][x - start_r][y - start_c])
            {
                board[x][y] = true;
            }
        }
    }
    return true;
}

bool CanAttachSticker(int idx)
{
    int r, c;
    tie(r, c) = stickers_rc[idx];

    for (int x = 0; x <= height - r; ++x)
    {
        for (int y = 0; y <= width - c; ++y)
        {
            if (AttachSticker(x, y, idx))
            {
                return true;
            }
        }
    }
    return false;
}

void RotateSticker(int idx)
{
    int r, c;
    tie(r, c) = stickers_rc[idx];
    
    for (int x = 0; x < r; ++x)
    {
        for (int y = 0; y < c; ++y)
        {
            temp_sticker[y][r-x-1] = stickers[idx][x][y];
            stickers[idx][x][y] = false;
        }
    }

    stickers_rc[idx] = { c,r };

    for (int x = 0; x < c; ++x)
    {
        for (int y = 0; y < r; ++y)
        {
            stickers[idx][x][y] = temp_sticker[x][y];
        }
    }
}

void PrintBoard()
{
    for (int r = 0; r < height; ++r)
    {
        for (int c = 0; c < width; ++c)
        {
            cout << board[r][c]<<" ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int Solution()
{
    int total_cnt = 0;
    int rotate_cnt;

    for (int i = 0; i < sticker_cnt; ++i)
    {
        rotate_cnt = 0;
        while (rotate_cnt < 4)
        {
            if (CanAttachSticker(i))
            {
                //PrintBoard();
                total_cnt += stickers_area_cnt[i];
                break;
            }

            ++rotate_cnt;
            RotateSticker(i);
        }
    }

    return total_cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    Input();
    cout << Solution();

    return 0;
}