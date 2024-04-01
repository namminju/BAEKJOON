#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int max_safe_area = 0;
stack<pair<int, int>> virus;

int x_[4] = { 1, -1, 0, 0};
int y_[4] = { 0, 0, 1, -1};

int BFS_cal_area(vector<vector<int>> Lab) {
    int result = 0;
    stack<pair<int, int>> q = virus;
    while (!q.empty()) {
        int x = q.top().first;
        int y = q.top().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (x + x_[i] >= 0 && x + x_[i] < n && y + y_[i] >= 0 && y + y_[i] < m && Lab[x + x_[i]][y + y_[i]] == 0) {
                Lab[x + x_[i]][y + y_[i]] = 2;
                q.push(make_pair(x + x_[i], y + y_[i]));
            }            
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Lab[i][j] == 0) {
                result++;
            }
        }
    }
    return result;
}

void Build(vector<vector<int>> &Lab, int cnt) {
    if (cnt == 3) {
        max_safe_area = max(max_safe_area, BFS_cal_area(Lab));
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (Lab[i][j] == 0) {
                Lab[i][j] = 1;
                Build(Lab, cnt + 1);
                Lab[i][j] = 0;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;

    vector<vector<int>> Lab(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> Lab[i][j];
            if (Lab[i][j] == 2) {
                virus.push(make_pair(i,j));
            }
        }
    }

    Build(Lab, 0);

    cout << max_safe_area;
    return 0;
}
