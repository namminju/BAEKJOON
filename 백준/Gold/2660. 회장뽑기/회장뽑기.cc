#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

vector<vector<int>> friends;
vector<int> cman;
int p;
int small = 100;

int bfs(int start) {
    vector<bool> visited(p + 1, false);
    vector<int> distance(p + 1, 0);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    int max_distance = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int n : friends[node]) {
            if (!visited[n]) {
                visited[n] = true;
                q.push(n);
                distance[n] = distance[node] + 1;
                max_distance = max(max_distance, distance[n]);
            }
        }
    }
    return max_distance;
}

int main() {
    cin >> p;
    friends.resize(p + 1); 

    while (true) {
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 == -1 && c2 == -1) {
            break;
        }
        friends[c1].push_back(c2);
        friends[c2].push_back(c1);
    }

    cman.resize(p + 1, 0);

    for (int i = 1; i <= p; i++) {
        cman[i] = bfs(i);
    }

    for (int i = 1; i <= p; i++) {
        small = min(small, cman[i]);
    }

    set<int> candidate;
    for (int i = 1; i <= p; i++) {
        if (cman[i] == small) {
            candidate.insert(i);
        }
    }

    cout << small << " " << candidate.size() << "\n";
    for (int id : candidate) {
        cout << id << " ";
    }
    cout << "\n";
    return 0;
}
