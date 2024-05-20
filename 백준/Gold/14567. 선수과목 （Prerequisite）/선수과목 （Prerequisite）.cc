#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> Sub(N + 1);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        Sub[b].push_back(a);
    }

    vector<int> result(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        int max_semester = 0;
        for (int pre : Sub[i]) {
            max_semester = max(max_semester, result[pre]);
        }
        result[i] = max_semester + 1;
    }

    for (int i = 1; i <= N; ++i) {
        cout << result[i] << "\n";
    }

    return 0;
}
