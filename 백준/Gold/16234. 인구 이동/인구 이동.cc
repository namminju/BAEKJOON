#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

struct Region {
    int population;
    bool check;
};

int n, l, r;
vector<vector<Region>> A;
vector<pair<int, int>> v;

int Next[4][2] = {
    {-1, 0}, {1, 0}, {0, 1}, {0, -1}
};

bool shouldOpen(int a, int b) {
    return abs(a - b) >= l && abs(a - b) <= r;
}

int main() {
    cin >> n >> l >> r;

    A.resize(n, vector<Region>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j].population;
        }
    }

    int days = 0;

    while (true) {
        bool moved = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!A[i][j].check) {
                    int country = 1;
                    int population = A[i][j].population;

                    queue<pair<int, int>> q;
                    q.push({ j, i });
                    v.push_back({ j, i });
                    A[i][j].check = true;

                    while (!q.empty()) {
                        int cur_x = q.front().first;
                        int cur_y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int dx = cur_x + Next[k][0];
                            int dy = cur_y + Next[k][1];

                            if (dx < n && dy < n && dx >= 0 && dy >= 0 && !A[dy][dx].check && shouldOpen(A[cur_y][cur_x].population, A[dy][dx].population)) {
                                A[dy][dx].check = true;
                                q.push({ dx, dy });
                                v.push_back({ dx, dy });
                                country++;
                                population += A[dy][dx].population;
                                moved = true;
                            }
                        }
                    }

                    int avg = population / country;

                    for (int k = 0; k < v.size(); k++) {
                        A[v[k].second][v[k].first].population = avg;
                    }
                    v.clear();
                }
            }
        }

        if (!moved) {
            break;
        }

        days++;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j].check = false;
            }
        }
    }

    cout << days;

    return 0;
}
