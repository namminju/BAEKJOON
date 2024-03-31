#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, v;

void DFS(vector<vector<int>> edge, vector<bool> visit) {
   
    for (int i = 0; i <= n; i++) {

        sort(edge[i].begin(), edge[i].end(), greater<int>());

    }

    stack<int> DFS;
    DFS.push(v);

    while (!DFS.empty()) {
        int now = DFS.top();
        if (!visit[now]) {
            cout << now << " ";
        }
        visit[now] = true;

        if (!edge[now].empty()) {
            if (!visit[edge[now].back()]) {
                DFS.push(edge[now].back());
            }
            edge[now].pop_back();
        }
        else {
            DFS.pop();
        }

    }

}

void BFS(vector<vector<int>> edge, vector<bool> visit) {
    
    for (int i = 0; i <= n; i++) {

        sort(edge[i].begin(), edge[i].end());

    }

    fill_n(visit.begin(), n + 1, false);
    queue<int> BFS;
    BFS.push(v);

    while (!BFS.empty()) {
        int now = BFS.front();
        BFS.pop();
        visit[now] = true;
        for (int i = 0; i < edge[now].size(); i++) {
            if (!visit[edge[now][i]]) {
                BFS.push(edge[now][i]);
                visit[edge[now][i]] = true;
            }
        }
        cout << now << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m >> v;
    vector<vector<int>> edge(n + 1);
    vector<bool> visit(n + 1, false);

    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }

    DFS(edge, visit);
    cout << "\n";
    BFS(edge, visit);

    return 0;
}
