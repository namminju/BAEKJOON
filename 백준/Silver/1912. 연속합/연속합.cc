#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int* num = new int[n];
    int* DP = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int max_sum = num[0];
    DP[0] = num[0];
    for (int i = 1; i < n; i++) {
        DP[i] = max(DP[i-1] + num[i], num[i]);
        if (DP[i] > max_sum) {
            max_sum = DP[i];
        }
    }
    cout << max_sum;
    delete[] DP;
    delete[] num;
    return 0;
}
