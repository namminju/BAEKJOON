#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> person(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> person[i][j];
            if (j > 0) {
                person[i][j] += person[i][j - 1]; 
            }
        }
    }

    int doit;
    cin >> doit;

    for (int i = 0; i < doit; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int result = 0;
        for (int j = x1 - 1; j < x2; j++) {
            result += person[j][y2 - 1];
            if (y1 > 1) {
                result -= person[j][y1 - 2]; 
            }
        }
        cout << result << "\n";
    }
    return 0;
}
