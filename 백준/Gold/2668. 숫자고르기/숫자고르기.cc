#include <iostream>
#include <vector>
#include <set>
using namespace std;
set<int> answer;

void DFS(vector<bool> visited, vector<int> &graph, int cur, int start) {
    if (!visited[cur]) {
        visited[cur] = true;
        DFS(visited, graph, graph[cur], start);
    }
    else if (cur == start) {
        answer.insert(start);
        return;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> graph(n + 1);
    vector<bool> visited(n + 1, false);


    for (int i = 1; i <= n; ++i)
        cin >> graph[i];

    for (int i = 1; i <= n; ++i) {
        DFS(visited, graph, i, i);
    }

    cout << answer.size() << "\n";
    for (int a : answer)
        cout << a << "\n";

    return 0;
}
