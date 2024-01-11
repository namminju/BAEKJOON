#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    map<int, int> parent;
    vector<vector<int>> tree(n + 1);

    for (int i = 1; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    vector<bool> visited(n + 1, false);
    vector<int> stack;

    stack.push_back(1);

    while (!stack.empty()) {
        int current = stack.back();
        stack.pop_back();

        visited[current] = true;

        for (int child : tree[current]) {
            if (!visited[child]) {
                parent[child] = current;
                stack.push_back(child);
            }
        }
    }


    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}
