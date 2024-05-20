#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> lose(N), get(N);
    for (int i = 0; i < N; ++i) {
        cin >> lose[i];
    }    
    for (int i = 0; i < N; ++i) {
        cin >> get[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(100 + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (lose[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - lose[i - 1]] + get[i - 1]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][99] << endl;

    return 0;
}
