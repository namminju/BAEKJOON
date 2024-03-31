#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct dis
{
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, v;
    cin >> n >> m >> v;
    vector<vector<int>> edge(n + 1);
    vector<vector<int>> edge_copy(n + 1);
    vector<bool> visit(n + 1, false);
    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        edge[n1].push_back(n2);
        edge[n2].push_back(n1);
    }

    edge_copy = edge;

    for (int i = 0; i <= n; i++) {

        sort(edge_copy[i].begin(), edge_copy[i].end(), greater<int>());

    }
    stack<int> DFS;
    DFS.push(v);

    while (!DFS.empty()) {
        int now = DFS.top();
        if (!visit[now]) {
            cout << now << " ";
        }
        visit[now] = true;

        if (!edge_copy[now].empty()) {
            if (!visit[edge_copy[now].back()]) {
                DFS.push(edge_copy[now].back());
            }
            edge_copy[now].pop_back();
        }
        else {
            DFS.pop();
        }

    }
    cout << "\n";



    for (int i = 0; i <= n; i++) {

        sort(edge[i].begin(), edge[i].end());

    }

    fill_n(visit.begin(), n+1, false);
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

    return 0;
}
