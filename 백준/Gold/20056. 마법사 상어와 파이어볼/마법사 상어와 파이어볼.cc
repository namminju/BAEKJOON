#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
#include <queue>
using namespace std;

int n;
int graph[51][51] = { 0 };

int move(int i) {
    i = i % n;
    if (i < 1) {
        i += n;
    }
    return i;
}

pair<int, int> moveFireBall(int r, int c, int s, int d) {
    switch (d) {
    case 0:
        r = move(r - s);
        break;
    case 1:
        r = move(r - s);
        c = move(c + s);
        break;
    case 2:
        c = move(c + s);
        break;
    case 3:
        r = move(r + s);
        c = move(c + s);
        break;
    case 4:
        r = move(r + s);
        break;
    case 5:
        r = move(r + s);
        c = move(c - s);
        break;
    case 6:
        c = move(c - s);
        break;
    case 7:
        r = move(r - s);
        c = move(c - s);
        break;
    default:
        break;
    }
    return make_pair(r, c);
}

struct FireBall {
    int r;
    int c;
    int m;
    int s;
    int d;

    bool operator<(const FireBall f) const {
        if (this->r == f.r) {
            return this->c > f.c;
        }
        else {
            return this->r > f.r;
        }
    }
};

int main() {
    int m, k;
    cin >> n >> m >> k;

    priority_queue<FireBall> fires;

    for (int i = 0; i < m; i++) {
        FireBall tmp;
        cin >> tmp.r >> tmp.c >> tmp.m >> tmp.s >> tmp.d;
        fires.push(tmp);
    }

    for (int i = 0; i < k; i++) {
        map<pair<int, int>, vector<FireBall>> next;

        while (!fires.empty()) {
            FireBall tmp = fires.top();
            fires.pop();
            tie(tmp.r, tmp.c) = moveFireBall(tmp.r, tmp.c, tmp.s, tmp.d);
            next[{tmp.r, tmp.c}].push_back(tmp);
        }

        fires = priority_queue<FireBall>();

        for (auto& entry : next) {
            if (entry.second.size() > 1) {
                int total_m = 0, total_s = 0;
                bool same_dir = true;
                int first_dir_mod = entry.second[0].d % 2;
                for (auto& fb : entry.second) {
                    total_m += fb.m;
                    total_s += fb.s;
                    if (fb.d % 2 != first_dir_mod) {
                        same_dir = false;
                    }
                }
                int new_m = total_m / 5;
                int new_s = total_s / entry.second.size();
                if (new_m > 0) {
                    for (int j = 0; j < 4; j++) {
                        FireBall new_fb = { entry.first.first, entry.first.second, new_m, new_s, same_dir ? j * 2 : j * 2 + 1 };
                        fires.push(new_fb);
                    }
                }
            }
            else {
                fires.push(entry.second[0]);
            }
        }
    }

    int result = 0;
    while (!fires.empty()) {
        FireBall tmp = fires.top();
        fires.pop();
        result += tmp.m;
    }

    cout << result;
    return 0;
}
