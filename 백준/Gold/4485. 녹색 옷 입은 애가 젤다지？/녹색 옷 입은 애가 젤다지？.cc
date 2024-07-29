#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

const int INF = 9999;

// 방향 벡터: 상, 하, 좌, 우
const int dRow[] = { -1, 1, 0, 0 };
const int dCol[] = { 0, 0, -1, 1 };

void dijkstra(const vector<vector<int>>& grid, vector<vector<int>>& dist, int startRow, int startCol) {
    int rows = grid.size();
    int cols = grid[0].size();

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

    pq.push({ grid[startRow][startCol], {startRow, startCol} });
    dist[startRow][startCol] = grid[startRow][startCol];

    while (!pq.empty()) {
        int curDist = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if (curDist > dist[row][col]) continue;

        for (int i = 0; i < 4; ++i) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                int newDist = curDist + grid[newRow][newCol];
                if (newDist < dist[newRow][newCol]) {
                    dist[newRow][newCol] = newDist;
                    pq.push({ newDist, {newRow, newCol} });
                }
            }
        }
    }
}

void doit(int n, int i) {
    vector<vector<int>> graph(n, vector<int>(n));
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            cin >> graph[j][k];
        }
    }

    dijkstra(graph, dist, 0, 0);

    cout << "Problem " << i << ": " << dist[n - 1][n - 1] << "\n";
}

int main() {
    int i = 1;

    while (true) {
        int n;
        cin >> n;
        if (n == 0) { break; }
        doit(n, i);
        i++;
    }

    return 0;
}
