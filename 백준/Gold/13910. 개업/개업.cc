#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define MAX 10001

vector<int> DP(MAX, MAX);
vector<int> wok;
set<int> Twowok;
void TwoWok() {
    for (int i = 0; i < wok.size(); i++) {
        for (int j = i + 1; j < wok.size(); j++) {
            Twowok.insert(wok[i] + wok[j]);
            //cout << wok[i] + wok[j] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        wok.push_back(tmp);
    }

    sort(wok.begin(), wok.end());
    TwoWok();

    DP[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (auto tmp : wok) {
            if (i >= tmp) {
                DP[i] = min(DP[i], DP[i - tmp] + 1);
            }
        }
        for (auto tmp : Twowok) {
            if (i >=     tmp) {
                DP[i] = min(DP[i], DP[i - tmp] + 1);
            }
        }
    }

    if (DP[n] > 10000) {
        cout << -1;
    }
    else {
        cout << DP[n];
    }
    return 0;
}
