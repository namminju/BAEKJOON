#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    int min_height;
    int n, m;
    cin >> n >> m;

    vector<int> loc(m);

    for (int i = 0; i < m; i++) {
        cin >> loc[i];
    }
    min_height = loc[0];
    for (int i = 1; i < m; i++) {
        min_height = max(min_height, (loc[i] - loc[i - 1] + 1) / 2);
    }
    min_height = max(min_height, n - loc.back());

    cout << min_height;
    return 0;
}
