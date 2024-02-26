#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1) {
        string s, t;
        cin >> s >> t;
        int s_now = 0;
        if (s == "")break;
        for (int i = 0; i < t.size(); i++) {
            if (s[s_now] == t[i]) {
                s_now++;
            }
        }
        if (s_now == s.size()) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
