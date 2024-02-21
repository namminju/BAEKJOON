#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_set>
using namespace std;
int n;

bool check(vector<vector<int>> graph, int start, int reach) {
    vector<bool> visited(n, false);
    vector<int> route = graph[start];
    while (!route.empty()) {
        int back = route.back();
        route.pop_back();

        if (back == reach) {
            return true;
        }
        if (!visited[back]) {
            for (auto tmp : graph[back]) {
                route.push_back(tmp);
            }
        }
        visited[back] = true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                graph[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(graph, i, j)) {
                cout << "1" << " ";
            }
            else {
                cout << "0" << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
