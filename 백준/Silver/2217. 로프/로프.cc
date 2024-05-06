#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> ropes(n);
    for (int i = 0; i < n; ++i) {
        cin >> ropes[i];
    }

    // 로프를 내림차순으로 정렬
    sort(ropes.begin(), ropes.end(), greater<int>());

    int maxWeight = 0;
    for (int i = 0; i < n; ++i) {
        maxWeight = max(maxWeight, ropes[i] * (i + 1));
    }

    cout << maxWeight << endl;

    return 0;
}
