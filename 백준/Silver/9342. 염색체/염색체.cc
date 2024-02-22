#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;

vector<char> condition = {'A', 'B','C','D','E', 'F'};
bool check(char input) {
    for (auto tmp : condition) {
        if (input == tmp) {
            return true;
        }
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string tmp; int now = 0; bool A = false, F = false, C = false;
        cin >> tmp;

        if (tmp[0] == 'A') {
            A = true;
        }
        for (int i = 1; i < tmp.size() - 1; i++) {
            while (tmp[i] == 'A') {
                A = true;
                i++;
            }
            if (tmp[i] != 'F') {
                break;
            }
            while (tmp[i] == 'F') {
                F = true;
                i++;
            }
            if (tmp[i] != 'C') {
                break;
            }
            while (tmp[i] == 'C') {
                C = true;
                i++;
            }
            if (tmp[i] != 'C') {
                break;
            }
        }

        if (check(tmp[0]) && check(tmp[tmp.size() - 1]) && A && F && C) {
            cout << "Infected!" << "\n";
        }
        else {
            cout << "Good" << "\n";
        }
    }

    return 0;
}
