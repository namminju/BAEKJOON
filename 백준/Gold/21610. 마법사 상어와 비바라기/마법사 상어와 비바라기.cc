#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m;
int graph[51][51];
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1}; // ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int move(int i) {
    if (i < 1) return n;
    if (i > n) return 1;
    return i;
}

pair<int, int> moveStorm(int r, int c, int s, int d) {
    r = (r + dx[d - 1] * s) % n;
    c = (c + dy[d - 1] * s) % n;
    if (r <= 0) r += n;
    if (c <= 0) c += n;
    return make_pair(r, c);
}

struct Storm {
    int r, c;
    Storm(int r, int c) : r(r), c(c) {}
};

int main() {
    cin >> n >> m;
    vector<Storm> storms;
    storms.push_back(Storm(n, 1));
    storms.push_back(Storm(n, 2));
    storms.push_back(Storm(n - 1, 1));
    storms.push_back(Storm(n - 1, 2));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        int d, s;
        cin >> d >> s;
        map<pair<int, int>, bool> visit;
        vector<Storm> next;

        for (Storm storm : storms) {
            tie(storm.r, storm.c) = moveStorm(storm.r, storm.c, s, d);
            next.push_back(storm);
            graph[storm.r][storm.c] += 1;
        }

        for (Storm storm : next) {
            int cnt = 0;
            if (storm.r > 1 && storm.c > 1 && graph[storm.r - 1][storm.c - 1] > 0) cnt++;
            if (storm.r > 1 && storm.c < n && graph[storm.r - 1][storm.c + 1] > 0) cnt++;
            if (storm.r < n && storm.c > 1 && graph[storm.r + 1][storm.c - 1] > 0) cnt++;
            if (storm.r < n && storm.c < n && graph[storm.r + 1][storm.c + 1] > 0) cnt++;
            graph[storm.r][storm.c] += cnt;
            visit[make_pair(storm.r, storm.c)] = true;
        }

        storms.clear();
        for (int r = 1; r <= n; r++) {
            for (int c = 1; c <= n; c++) {
                if (graph[r][c] >= 2 && !visit[make_pair(r, c)]) {
                    storms.push_back(Storm(r, c));
                    graph[r][c] -= 2;
                }
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            result += graph[i][j];
        }
    }
    cout << result << endl;

    return 0;
}
