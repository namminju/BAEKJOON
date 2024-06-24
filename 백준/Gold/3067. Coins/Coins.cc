#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int DP[10001] = { 0 };


int main() {
    int t;
    cin >> t;
    DP[0] = 1;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int coin;
            cin >> coin;
            for (int k = 1; k <= 10000; k++) {
                if (k >= coin) {
                    DP[k] = DP[k] + DP[k - coin];
                }
            }
        }
        cin >> m;
        cout << DP[m] << "\n";

        for (int k = 1; k <= 10000; k++) {
            DP[k] = 0;
        }
    }
    return 0;
}
