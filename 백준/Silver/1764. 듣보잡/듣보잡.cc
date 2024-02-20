#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    map <string, pair<bool, bool> > name;
    vector<string> name_book;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        name_book.push_back(tmp);
        name[tmp].first = true;
    }
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        name[tmp].second = true;
        if (!name[tmp].first) {
            name_book.push_back(tmp);
        }
    }



    int count = 0;
    vector<string> not_hs;
    for (auto tmp : name_book) {
        if (name[tmp].first && name[tmp].second) {
            not_hs.push_back(tmp);
            count++;
        }
    }

    sort(not_hs.begin(), not_hs.end());
    cout << count << "\n";

    for (auto tmp : not_hs) {
        cout << tmp << "\n";
    }

    return 0;
}
