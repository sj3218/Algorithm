#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

#define BOARD_SIZE  10
#define WALL        6
#define BLIND       0
#define DETECTED    100
#define INF         0X7FFFFFFF

int height, width;
int board[BOARD_SIZE][BOARD_SIZE];
int answer = INF;
vector<tuple<int, int, int>> cameras;
int cam_cnt;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<vector<int>> cam_3 = { {1,2},{2,0},{0,3},{3,1} };
vector<vector<int>> cam_4 = { {3,1,2},{1,2,0},{2,0,3},{0,3,1} };

bool IsValid(int x, int y)
{
    if (x <= 0 || y <= 0 || x > width || y > height)
        return false;
    return true;
}

void UpdateDetectedSpot(int x, int y, int dir, int map[][BOARD_SIZE])
{
    int nx = x;
    int ny = y;
    while (true)
    {
        nx += dx[dir];
        ny += dy[dir];

        if (!IsValid(nx, ny) || map[ny][nx] == WALL)
            break;

        if (1 <= map[ny][nx] && map[ny][nx] <= 5)
            continue;

        map[ny][nx] = DETECTED;
    }
}

int CountBlindSpot(int map[][BOARD_SIZE])
{
    int cnt = 0;
    for (int i = 1; i <= height; ++i)
    {
        for (int j = 1; j <= width; ++j)
        {
            if (map[i][j] == BLIND)
                ++cnt;
        }
    }
    return cnt;
}

void print_map(int map[][BOARD_SIZE])
{
    cout << "\n";
    for (int i = 1; i <= height; ++i)
    {
        for (int j = 1; j <= width; ++j)
        {
            if (map[i][j] == DETECTED)
                cout << ". ";
            else
                cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
void CopyMap(int map1[][BOARD_SIZE], int map2[][BOARD_SIZE])
{
    for (int i = 1; i <= height; ++i)
    {
        for (int j = 1; j <= width; ++j)
        {
            map1[i][j] = map2[i][j];
        }
    }
}

void dfs(int idx, int map[][BOARD_SIZE])
{
    //print_map(map);

    if (idx == cam_cnt)
    {
        answer = min(answer, CountBlindSpot(map));
        return;
    }

    int type, x, y;
    tie(type, x, y) = cameras[idx];

    int temp_map[BOARD_SIZE][BOARD_SIZE];
    if (type == 1)
    {
        for (int i = 0; i < 4; ++i)
        {
            CopyMap(temp_map, map);
            UpdateDetectedSpot(x, y, i, temp_map);
            dfs(idx + 1, temp_map);
        }
    }
    else if (type == 2)
    {
        for (int i = 0; i < 4; i += 2)
        {
            CopyMap(temp_map, map);
            UpdateDetectedSpot(x, y, i, temp_map);
            UpdateDetectedSpot(x, y, i + 1, temp_map);
            dfs(idx + 1, temp_map);
        }
    }
    else if (type == 3)
    {
        int a, b;
        for (int i = 0; i < 4; ++i)
        {
            CopyMap(temp_map, map);
            a = cam_3[i][0];
            b = cam_3[i][1];
            UpdateDetectedSpot(x, y, a, temp_map);
            UpdateDetectedSpot(x, y, b, temp_map);
            dfs(idx + 1, temp_map);
        }
    }
    else if (type == 4)
    {
        int a, b, c;
        for (int i = 0; i < 4; ++i)
        {
            CopyMap(temp_map, map);
            a = cam_4[i][0];
            b = cam_4[i][1];
            c = cam_4[i][2];
            UpdateDetectedSpot(x, y, a, temp_map);
            UpdateDetectedSpot(x, y, b, temp_map);
            UpdateDetectedSpot(x, y, c, temp_map);
            dfs(idx + 1, temp_map);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> height >> width;
    vector<pair<int, int>> type_five_cams;

    for (int i = 1; i <= height; ++i)
    {
        for (int j = 1; j <= width; ++j)
        {
            cin >> board[i][j];
            if (1 <= board[i][j] && board[i][j] <= 4)
                cameras.push_back({ board[i][j], j,i });
            else if (board[i][j] == 5)
                type_five_cams.push_back({ j,i });
        }
    }

    //detected blind spot using  type five cam
    for (pair<int, int> cam : type_five_cams)
    {
        for(int i = 0; i< 4; ++i)
            UpdateDetectedSpot(cam.first, cam.second, i, board);
    }

    cam_cnt = cameras.size();
    
    dfs(0, board);
    cout << answer;

    return 0;
}