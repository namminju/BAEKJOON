#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, K;
    cin >> n;

    vector<pair<int, int>> energy(n);
    vector<vector<int>> dp(n + 1, vector<int>(2, INT_MAX));
    dp[1][0] = 0;
    dp[1][1] = 0;

    for (int i = 1; i < n; ++i) {
        cin >> energy[i].first >> energy[i].second;
    }
    cin >> K;

    for (int i = 1; i <= n - 1; ++i) {
        if (i + 1 <= n) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + energy[i].first);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + energy[i].first);
        }

        if (i + 2 <= n) {
            dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + energy[i].second);
            dp[i + 2][1] = min(dp[i + 2][1], dp[i][1] + energy[i].second);
        }

        if (i + 3 <= n) {
            dp[i + 3][1] = min(dp[i + 3][1], dp[i][0] + K);
        }
    }

    int minEnergy = min(dp[n][0], dp[n][1]);
    cout << minEnergy;
    

    return 0;
}
