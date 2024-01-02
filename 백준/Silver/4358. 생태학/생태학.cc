#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string name;
    map<string,int> tree;
    int whole = 0;
    while (getline(cin, name) && !name.empty()) {
        whole++;
        if (!tree[name]) { tree[name] = 0; }
        tree[name]++;
    }

    for (auto iter : tree) {
        cout.precision(4);
        cout << fixed;
        cout << iter.first << " " << ((double)iter.second / whole) * 100 << "\n";
    }
    return 0;
}
