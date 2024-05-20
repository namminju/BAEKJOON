#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<int> study_time(N), score(N);
    for (int i = 0; i < N; ++i) {
        cin >> study_time[i] >> score[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= T; ++j) {
            if (study_time[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - study_time[i - 1]] + score[i - 1]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][T] << endl;

    return 0;
}
