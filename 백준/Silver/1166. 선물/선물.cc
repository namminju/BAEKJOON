#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, L, W, H;
    cin >> n >> L >> W >> H;

    double result = 0;
    vector<int> boxes = { L, W, H };
    sort(boxes.begin(), boxes.end());

    long double left = 0, right = boxes[2];

    for (int i = 0; i < 100000;i++) {
        long double mid = (left + right) / 2.0;
        long long count = (long long)(L / mid) * (long long)(W / mid) * (long long)(H / mid);

        if (count >= n) {
            left = mid;
        }
        else {
            right = mid;
        }
    }

    cout << fixed;
    cout.precision(15);
    cout << left << endl;

    return 0;
}
