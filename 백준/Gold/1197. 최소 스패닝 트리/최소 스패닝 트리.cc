#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
public:
    int V;
    vector<Edge> edges;

    Graph(int v) {
        V = v;
    }

    void addEdge(int src, int dest, int weight) {
        Edge edge;
        edge.src = src;
        edge.dest = dest;
        edge.weight = weight;
        edges.push_back(edge);
    }

    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent, parent[i]); 
    }

    void Union(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (xroot != yroot) {
            if (rank[xroot] < rank[yroot])
                swap(xroot, yroot);
            parent[yroot] = xroot;
            if (rank[xroot] == rank[yroot])
                rank[xroot]++;
        }
    }

    int KruskalMST() {
        int totalWeight = 0;

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
            });

        vector<int> parent(V, -1);
        vector<int> rank(V, 0); 

        for (Edge& edge : edges) {
            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);
            if (x != y) {
                Union(parent, rank, x, y);
                totalWeight += edge.weight;
            }
        }

        return totalWeight;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    Graph graph(v);
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.addEdge(a - 1, b - 1, c);
    }
    cout << graph.KruskalMST() << endl;

    return 0;
}
