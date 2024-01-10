#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;
    map<int, bool>num;
    for (int i = 2; i <= n; i++) {
        num[i] = true;
    }
    int now = 0;
    while (k != now) {
        int p = 0;
        for (int i = 2; i <= n; i++) {
            if (num[i]) {
                p = i;
                break;
            }
        }
        for (int i = 1; i * p <= n; i++) {
            if (num[i * p]) {
                num[i * p] = false;
                now++;
                if (now == k) { cout << i * p; break; }
            }
        }
    }
    return 0;
}
