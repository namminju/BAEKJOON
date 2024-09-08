#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int day[366] = { 0, };
int result = 0, big = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        for (int j = s; j <= e; j++) {
            day[j]++;
        }
        big = max(big, e);
    }

    int sequence = 0, sb = 0;
    for (int i = 1; i <= big; i++) {  
        if (day[i] > 0) {
            sequence++;
            sb = max(sb, day[i]);
        }
        else {
            if (sequence > 0) {
                result += sequence * sb;
                sequence = 0;
                sb = 0;
            }
        }
    }

    if (sequence > 0) {
        result += sequence * sb;
    }

    cout << result;
    return 0;
}
