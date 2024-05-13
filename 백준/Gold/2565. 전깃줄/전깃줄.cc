#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define MAX 10001



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<pair<int, int>> Line;
    int t, m=0;
    cin >> t;
    vector<int> DP(t);
    for (int i = 0; i < t; i++) {
        int s, e;
        cin >> s >> e;
        Line.push_back(make_pair(s, e));
    }

    sort(Line.begin(), Line.end());

    for (int i = 0; i < t; i++) {
        DP[i] = 1;
        for (int j = 0; j < i; j++) {
            if (Line[j].second < Line[i].second) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
        m = max(m, DP[i]);
    }

    cout << t - m;
    return 0;
}
