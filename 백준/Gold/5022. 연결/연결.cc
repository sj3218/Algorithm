
#include<iostream>

#include<queue>

#include<vector>

#include<cstring>

 

#define endl "\n"

#define MAX 101

using namespace std;

 

typedef struct

{

    int x;

    int y;

    vector<pair<int, int>> Route;

}Info;

 

int N, M, Answer = 999999999;

int A_Length, B_Length;

int MAP[MAX][MAX];

bool Temp_Visit[MAX][MAX];

int Visit[MAX][MAX];

bool A_Flag, B_Flag, Answer_Flag;

 

pair<int, int> A_Pos[2], B_Pos[2];

 

int dx[] = { 0, 0, 1, -1 };

int dy[] = { 1, -1, 0, 0 };

 

int Min(int A, int B) { if (A < B) return A; return B; }

 

void Print()

{

    cout << "###################################################" << endl;

    for (int i = 0; i <= N; i++)

    {

        for (int j = 0; j <= M; j++)

        {

            cout << Visit[i][j] << " ";

        }

        cout << endl;

    }

    cout << "###################################################" << endl;

}

 

void Input()

{

    cin >> M >> N;

 

    for (int i = 0; i < 2; i++)

    {

        int x, y; cin >> x >> y;

        A_Pos[i].first = y;

        A_Pos[i].second = x;

    }

    for (int i = 0; i < 2; i++)

    {

        int x, y; cin >> x >> y;

        B_Pos[i].first = y;

        B_Pos[i].second = x;

    }

}

 

void BFS(int a, int b, int da, int db, char c)

// BFS(시작 x좌표, 시작 y좌표, 도착 x좌표, 도착 y좌표, A를 까는지 or B를 까는지 구분)

{

    queue<Info> Q;

    // 위에서 말한대로 구조체를 자료형으로 사용하는 Queue 선언.

    vector<pair<int, int>> V;

    Info Temp;

    Temp.x = a; Temp.y = b; Temp.Route.push_back(make_pair(a, b));

    Q.push(Temp);

    // Queue에 초기값 Push

    Temp_Visit[a][b] = true;

    if (c == 'A') Visit[a][b] = 1;

    // A전선을 깔면 Visit배열을 1로 표현

    else Visit[a][b] = 2;

    // B전선을 깔면 Visit배열을 2로 표현

    // => 즉, Visit배열이 0이다 = 아무 전선도 깔려 있지 않은 곳이다 를 의미.

 

    while (Q.empty() == 0)

    {

        int x = Q.front().x;

        int y = Q.front().y;

        vector<pair<int, int>> R = Q.front().Route;

        Q.pop();

 

        if (x == da && y == db)    // 도착점에 도착한다면

        {

            if (c == 'A')        // A전선을 까는 중이였다면

            {

                A_Flag = true;    // A를 깔았다고 표시.

                for (int i = 0; i < R.size(); i++)

                {

                    int Rx = R[i].first;

                    int Ry = R[i].second;

                    Visit[Rx][Ry] = 1;

 

                    A_Length++;

                }

                // 위의 for문은 연결된 최단경로에 이미 전선을 깔았다고

                // 표시해주는 역할. 동시에 길이를 계산함.

            }

            else                // 위와 똑같은데, B전선을 까는 중이였다면 

            {

                B_Flag = true;

                for (int i = 0; i < R.size(); i++)

                {

                    int Rx = R[i].first;

                    int Ry = R[i].second;

                    Visit[Rx][Ry] = 2;

 

                    B_Length++;

                }

            }

            return;

        }

    

        for (int i = 0; i < 4; i++)

        {

            int nx = x + dx[i];

            int ny = y + dy[i];

            vector<pair<int, int>> nR;

 

            for (int j = 0; j < R.size(); j++) nR.push_back(R[j]);

            // 기존의 Route를 일단 다 옮겨준다.

            

            if (nx < 0 || ny < 0 || nx > N || ny > M) continue;

            // 범위Out이면 continue

            if (c == 'A')    

            {

                if ((nx == B_Pos[0].first && ny == B_Pos[0].second) || (nx == B_Pos[1].first && ny == B_Pos[1].second)) continue;

                if (Temp_Visit[nx][ny] == true || Visit[nx][ny] != 0) continue;

                // A를 까는 중일 때, B의 2점 중 한 점이 있는 곳이라면 그곳에는 전선을 깔 수 없다.

                // A를 까는 중일 때, 이미 방문했거나, 이미 B의 전선이 깔려있는 곳이라면 전선을 깔 수 없다.

 

                Temp_Visit[nx][ny] = true;

                nR.push_back(make_pair(nx, ny));

                Q.push({ nx, ny, nR });

            }

            else // 위와 마찬가지인데 B전선을 까는 경우임. 즉, 비교해야될 조건만 A로 바뀌게 되는 것 ! 

            {

                if ((nx == A_Pos[0].first && ny == A_Pos[0].second) || (nx == A_Pos[1].first && ny == A_Pos[1].second)) continue;

                if (Temp_Visit[nx][ny] == true || Visit[nx][ny] != 0) continue;

 

                Temp_Visit[nx][ny] = true;

                nR.push_back(make_pair(nx, ny));

                Q.push({ nx, ny, nR });

            }

        }        

    }    

}

 

void Solution()

{

    int x = A_Pos[0].first;

    int y = A_Pos[0].second;

    int xx = A_Pos[1].first;

    int yy = A_Pos[1].second;

    BFS(x, y, xx, yy, 'A');

 

    memset(Temp_Visit, false, sizeof(Temp_Visit));

    x = B_Pos[0].first;

    y = B_Pos[0].second;

    xx = B_Pos[1].first;

    yy = B_Pos[1].second;

    BFS(x, y, xx, yy, 'B');

    

    if (A_Flag == true && B_Flag == true)

    {

        Answer_Flag = true;

        Answer = Min(Answer, A_Length + B_Length);

    }

 

    memset(Visit, 0, sizeof(Visit));

    memset(Temp_Visit, false, sizeof(Temp_Visit));

    A_Length = B_Length = 0;

    A_Flag = false;

    B_Flag = false;

 

    x = B_Pos[0].first;

    y = B_Pos[0].second;

    xx = B_Pos[1].first;

    yy = B_Pos[1].second;

    BFS(x, y, xx, yy, 'B');

 

    memset(Temp_Visit, false, sizeof(Temp_Visit));

    x = A_Pos[0].first;

    y = A_Pos[0].second;

    xx = A_Pos[1].first;

    yy = A_Pos[1].second;

    BFS(x, y, xx, yy, 'A');

 

    if (A_Flag == true && B_Flag == true)

    {

        Answer_Flag = true;

        Answer = Min(Answer, A_Length + B_Length);

    }

}

 

void Solve()

{

    Input();

    Solution();

 

    if (Answer_Flag == false) cout << "IMPOSSIBLE" << endl;

    else cout << Answer - 2 << endl;

}

 

int main(void)

{

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);

 

    //freopen("Input.txt", "r", stdin);

    Solve();

 

    return 0;

}