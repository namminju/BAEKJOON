#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

vector<int> buildCount;
vector<unordered_set<int>> prerequisites;
vector<int> inDegree;
int n, m, k;

bool YWAction(int action, int a) {
    if (action == 1) { // 건설
        if (inDegree[a] < 1) {
            buildCount[a]++;
            if (buildCount[a] == 1) {
                for (int pre : prerequisites[a]) {
                    inDegree[pre]--;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }
    else if (action == 2) { // 파괴
        if (buildCount[a] > 0) {
            buildCount[a]--;
            if (buildCount[a] == 0) {
                for (int pre : prerequisites[a]) {
                    inDegree[pre]++;
                }
            }
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    buildCount.resize(n + 1, 0);
    prerequisites.resize(n + 1);
    inDegree.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        prerequisites[x].insert(y);
        inDegree[y]++;
    }

    bool isPossible = true;
    for (int i = 0; i < k; i++) {
        int action, a;
        cin >> action >> a;
        if (!YWAction(action, a)) {
            isPossible = false;
            break;
        }
    }

    if (isPossible) {
        cout << "King-God-Emperor";
    }
    else {
        cout << "Lier!";
    }

    return 0;
}
