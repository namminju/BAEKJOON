#include <iostream>
#include <vector>
using namespace std;

long long combination(int n, int r) {
    if (r == 0 || n == r) return 1;
    if (r == 1) return n;

    vector<vector<long long>> dp(n + 1, vector<long long>(r + 1, 0));
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= r; ++j) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }
    return dp[n][r];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int k = 0; k < t; k++) {
        int n, m;
        cin >> n >> m;

        cout << combination(m, n) << "\n";
    }

    return 0;
}
