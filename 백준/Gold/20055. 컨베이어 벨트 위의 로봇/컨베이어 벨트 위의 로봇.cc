#include <iostream>
#include <deque>
using namespace std;

int N, K;
deque<int> belts;
deque<bool> has_robot;
int durability_cnt = 0;

void rotate() {
    belts.push_front(belts.back());
    belts.pop_back();
    has_robot.push_front(has_robot.back());
    has_robot.pop_back();
    has_robot[N - 1] = false; // 내리는 위치
}

void move_robots() {
    for (int i = N - 2; i >= 0; --i) {
        if (has_robot[i] && !has_robot[i + 1] && belts[i + 1] > 0) {
            has_robot[i] = false;
            has_robot[i + 1] = true;
            if (--belts[i + 1] == 0) ++durability_cnt;
        }
    }
    has_robot[N - 1] = false;
}

void place_robot() {
    if (belts[0] > 0 && !has_robot[0]) {
        has_robot[0] = true;
        if (--belts[0] == 0) ++durability_cnt;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0; i < 2 * N; ++i) {
        int a;
        cin >> a;
        belts.push_back(a);
        has_robot.push_back(false);
    }

    int step = 0;
    while (true) {
        ++step;
        rotate();
        move_robots();
        place_robot();

        if (durability_cnt >= K)
            break;
    }

    cout << step << '\n';
    return 0;
}
