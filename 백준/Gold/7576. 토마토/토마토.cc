#include <iostream>
#include <vector>
using namespace std;

struct Coordinate
{
    int x = 0;
    int y = 0;
};

bool isAllTomatoesRipe(const vector<vector<int>>& tomato) {
    for (const auto& row : tomato) {
        for (int element : row) {
            if (element == 0) {
                return false;
            }
        }
    }
    return true;
}

void TomatoRipe(int m, int n, vector<vector<int>>& tomato, vector<Coordinate>& x_y) {
    vector<Coordinate> newRipeTomatoes;

    for (Coordinate tmp : x_y) {
        int i = tmp.x, j = tmp.y;

        if (i > 0 && tomato[i - 1][j] == 0) {
            tomato[i - 1][j] = 1;
            newRipeTomatoes.push_back({ i - 1, j });
        }
        if (i + 1 < n && tomato[i + 1][j] == 0) {
            tomato[i + 1][j] = 1;
            newRipeTomatoes.push_back({ i + 1, j });
        }
        if (j + 1 < m && tomato[i][j + 1] == 0) {
            tomato[i][j + 1] = 1;
            newRipeTomatoes.push_back({ i, j + 1 });
        }
        if (j > 0 && tomato[i][j - 1] == 0) {
            tomato[i][j - 1] = 1;
            newRipeTomatoes.push_back({ i, j - 1 });
        }
    }

    x_y = newRipeTomatoes;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> tomato(n, vector<int>(m));
    vector<Coordinate> x_y;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                x_y.push_back({ i, j });
            }
        }
    }

    int day = 0;

    while (!isAllTomatoesRipe(tomato)) {
        day++;
        TomatoRipe(m, n, tomato, x_y);

        if (x_y.empty()) {
            cout << -1;
            return 0;
        }
    }

    cout << day;

    return 0;
}
