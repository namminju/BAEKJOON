#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<int> lan(k);
    for (int i = 0; i < k; i++) {
        cin >> lan[i];
    }

    sort(lan.begin(), lan.end(), greater<int>());


    long long left = 1, right = lan[0];

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (int i = 0; i < k; i++) {
            count += lan[i] / mid;
        }

        if (count >= n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << right;
    return 0;
}
