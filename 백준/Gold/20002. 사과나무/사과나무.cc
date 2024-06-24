#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> profit(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> prefixSum(n + 1, vector<int>(n + 1, 0));


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> profit[i][j];
            prefixSum[i][j] = profit[i][j] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    int maxProfit = -1000;

    for (int k = 1; k <= n; ++k) { 
        for (int i = k; i <= n; ++i) {
            for (int j = k; j <= n; ++j) {
                int totalProfit = prefixSum[i][j]
                    - prefixSum[i - k][j]
                    - prefixSum[i][j - k]
                    + prefixSum[i - k][j - k];
                maxProfit = max(maxProfit, totalProfit);
            }
        }
    }

    cout << maxProfit << endl;
    return 0;
}
