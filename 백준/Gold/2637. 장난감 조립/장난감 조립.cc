#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int indegree[101] = { 0 }; 
vector<pair<int, int>> parts[101]; 
int dp[101][101] = { 0 };

void topologicalSort() {
    queue<int> q;

    for (int i = 1; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
            dp[i][i] = 1; // 기본 부품
        }
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto& p : parts[now]) {
            int next = p.first; 
            int cnt = p.second; 

            for (int i = 1; i < n; i++) {
                dp[next][i] += dp[now][i] * cnt;
            }

            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, k;
        cin >> x >> y >> k;
        parts[y].push_back({ x, k }); 
        indegree[x]++;
    }

    topologicalSort();

    for (int i = 1; i < n; i++) {
        if (dp[n][i] > 0) { 
            cout << i << " " << dp[n][i] << "\n";
        }
    }

    return 0;
}
