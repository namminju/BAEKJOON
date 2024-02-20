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

    int n;
    cin >> n;
    vector<unordered_set<int>> friend_2(n);
    vector<int> num(n);
    vector<vector<int>> friend_list(n);
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            if (tmp[j] == 'Y') {
                friend_list[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto tmp : friend_list[i]) {
            friend_2[i].insert(tmp);
            for (auto tmp : friend_list[tmp]) {
                if (i != tmp) {
                    friend_2[i].insert(tmp);
                }
            }
        }
        num[i] = friend_2[i].size();
    }

    sort(num.begin(), num.end());

    cout << num.back();
    return 0;
}
