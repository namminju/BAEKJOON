#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> ve;
int* dp;

int solve(bool*& visit, int now) {
    visit[now] = true;

    for (int i = 0; i < ve[now].size(); i++) {
        int next = ve[now][i];
        if (!visit[next]) {
            dp[now] += solve(visit, next);
        }
    }

    return dp[now];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r, q;
    cin >> n >> r >> q;
    ve.resize(n + 1);
    dp = new int[n + 1];
    bool* visit = new bool[n + 1];

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        visit[i] = false; 
    }

    solve(visit, r);

    for (int i = 0; i < q; i++) {
        int tmp;
        cin >> tmp;
        cout << dp[tmp] << "\n";
    }

    delete[] dp;
    delete[] visit;
    return 0;
}
