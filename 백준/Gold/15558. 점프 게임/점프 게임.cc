#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int N, K;
int board[2][100001];
int is_visited[2][100001];
int dx[3] = { 1, -1, 0 };

int bfs() {
    queue<tuple<int, int, int>> q; // {시간, 현재 줄, 현재 칸}
    q.push({ 0, 0, 0 }); // {시간 0, 왼쪽 줄(0), 첫 번째 칸(0)}
    is_visited[0][0] = 1;

    while (!q.empty()) {
        int time = get<0>(q.front());
        int way = get<1>(q.front());
        int idx = get<2>(q.front());
        q.pop();

        for (int i = 0; i < 3; ++i) {
            int n_idx = idx + dx[i];
            int n_way = way;

            if (i == 2) { // 반대편으로 점프
                n_way = (way + 1) % 2;
                n_idx = idx + K;
            }

            // 게임 클리어 조건
            if (n_idx >= N) {
                return 1;
            }

            // 범위 검사 및 유효성 체크
            if (n_idx < 0 || n_idx <= time || is_visited[n_way][n_idx] || board[n_way][n_idx] == 0) {
                continue;
            }

            is_visited[n_way][n_idx] = 1;
            q.push({ time + 1, n_way, n_idx });
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    dx[2] = K;

    string left_s, right_s;
    cin >> left_s >> right_s;

    for (int i = 0; i < N; ++i) {
        board[0][i] = left_s[i] - '0';
        board[1][i] = right_s[i] - '0';
    }

    fill_n(is_visited[0], 100001 * 2, 0);
    cout << bfs();
    return 0;
}
