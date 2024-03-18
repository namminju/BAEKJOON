#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <limits>
using namespace std;
int dp[1005][1005][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill_n(&dp[0][0][0], 1005 * 1005 * 3, numeric_limits<int>::max());
    int n, m;
    cin >> n >> m;
    vector<vector<int>> fuel(n);
    vector<vector<int>> direc(n);
    for (int i = 0; i < n; i++) {
        direc[i].resize(m);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = 0;
            cin >> tmp;
            fuel[i].push_back(tmp);
        }
    }

    for (int j = 0; j < m; j++) {
        dp[0][j][0] = fuel[0][j];
        dp[0][j][1] = fuel[0][j];
        dp[0][j][2] = fuel[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0) {
                dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + fuel[i][j];
                dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + fuel[i][j];
            }
            else if (j == m - 1) {
                dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + fuel[i][j];
                dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + fuel[i][j];
            }
            else {
                dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + fuel[i][j];
                dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + fuel[i][j];
                dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + fuel[i][j];
            }
        }
    }
    int result = dp[n - 1][0][0];
    for (int j = 0; j < m; j++) {
        result=min(result,min(dp[n - 1][j][0],min(dp[n - 1][j][1], dp[n - 1][j][2])));
    }
    cout << result;

    return 0;
}
