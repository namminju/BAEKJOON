#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 401;
int graph[MAX_N][MAX_N];

void floydWarshall(int n) {
    // 플로이드-워셜 알고리즘을 이용하여 사건 간 전후 관계를 찾는다.
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

    // 그래프 초기화
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j) {
                graph[i][j] = 0; // 0은 전후 관계를 모름
            }
        }
    }

    // 사건의 전후 관계 입력
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
