#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);

    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> table(n, vector<int>(n));
    for (int i = 0; i < n * n; i++) {
        int temp = 0;
        cin >> temp;
        table[i/n][i%n] = temp;
    }
    int* last = new int[n];
    for (int i = 0; i < n; i++) {
        last[i] = n - 1;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        int max = INT_MIN;
        int now = 0;
        for (int j = 0; j < n; j++) {
            if (table[last[j]][j] > max) {
                max = table[last[j]][j];
                now = j;
            }
        }
        last[now] -= 1;
        result = max;
    }
    cout << result;
    delete[] last;
    return 0;
}
