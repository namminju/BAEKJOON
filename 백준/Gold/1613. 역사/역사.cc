#include <iostream>
#include <vector>
using namespace std;

int graph[401][401] = {0};

void floydWarshall(int n) {
    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= n; ++k) { // 중간 노드
        for (int i = 1; i <= n; ++i) { // 출발 노드
            for (int j = 1; j <= n; ++j) { // 도착 노드
                if (graph[i][k] == 1 && graph[k][j] == 1) {
                    graph[i][j] = 1;
                }
                else if (graph[i][k] == -1 && graph[k][j] == -1) {
                    graph[i][j] = -1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, s;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        int past, future;
        cin >> past >> future;
        graph[past][future] = -1;
        graph[future][past] = 1;
    }

    // 플로이드-워셜 알고리즘 수행
    floydWarshall(n);

    cin >> s;
    for (int i = 0; i < s; ++i) {
        int past, future;
        cin >> past >> future;
        cout << graph[past][future] << "\n";
    }

    return 0;
}
