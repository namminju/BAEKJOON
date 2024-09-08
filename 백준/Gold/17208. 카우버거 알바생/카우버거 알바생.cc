#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int DP[301][301][301] = { 0, };
int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    vector<int> CB(n + 1);
    vector<int> FF(n + 1);

    //주문 입력
    for (int i = 1; i <= n; i++) {
        cin >> CB[i] >> FF[i];
    }

    //계산
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int u = 1; u <= k; u++) {
                if (j >= CB[i] && u >= FF[i])
                    DP[i][j][u] = max(DP[i - 1][j][u], DP[i - 1][j - CB[i]][u - FF[i]] + 1);
                else
                    DP[i][j][u] = DP[i - 1][j][u];
            }
        }
    }

    cout << DP[n][m][k];
    return 0;
}
