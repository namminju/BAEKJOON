#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
        graph[i].resize(n);
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (i == 0 && j == 0) {
                graph[i][j] = tmp;
            }
            else if (i == 0) {
                graph[i][j] = graph[i][j - 1] + tmp;
            }
            else if (j == 0) {
                graph[i][j] = graph[i - 1][j] + tmp;
            }
            else {
                graph[i][j] = graph[i - 1][j] + graph[i][j - 1] - graph[i - 1][j - 1] + tmp;
            }
        }
    }

    for (int r = 0; r < m; r++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--; // Adjust indices
        if (x1 == 0 && y1 == 0) {
            cout << graph[x2][y2] << '\n';
        }
        else if (x1 == 0) {
            cout << graph[x2][y2] - graph[x2][y1 - 1] << '\n';
        }
        else if (y1 == 0) {
            cout << graph[x2][y2] - graph[x1 - 1][y2] << '\n';
        }
        else {
            cout << graph[x2][y2] - graph[x1 - 1][y2] - graph[x2][y1 - 1] + graph[x1 - 1][y1 - 1] << '\n';
        }
    }

    return 0;
}
