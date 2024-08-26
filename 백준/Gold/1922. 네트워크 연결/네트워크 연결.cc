#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct Route {
    int a, b, cost;
    Route(int a, int b, int cost) : a(a), b(b), cost(cost) {}

    bool operator<(const Route& other) const {
        return cost < other.cost;
    }
};


struct UnionFind {
    vector<int> parent, rank;

    UnionFind(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }

    bool unionSets(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false; 

        if (rank[u] > rank[v]) {
            parent[v] = u;
        }
        else if (rank[u] < rank[v]) {
            parent[u] = v;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<Route> routes;
    for (int i = 0; i < m; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        routes.push_back(Route(a - 1, b - 1, cost));
    }


    sort(routes.begin(), routes.end());

    UnionFind uf(n);
    int mst_cost = 0;

    for (const auto& route : routes) {
        if (uf.unionSets(route.a, route.b)) {
            mst_cost += route.cost;
        }
    }


    cout << mst_cost << '\n';


    return 0;
}
