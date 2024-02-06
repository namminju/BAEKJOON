#include<iostream>
#include<map>
#include<queue>
#include<cstring>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    map<int, bool> have;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        have[tmp] = true;
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if (have[tmp] == true) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }    }
    return 0;
}
