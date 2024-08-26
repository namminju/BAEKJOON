#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n;
class Trie {
public:
    map<string, Trie*> m;

    // insert 함수는 재귀적으로 Trie에 단어를 삽입합니다.
    void insert(const vector<string>& v, int i) {
        if (i == v.size()) {
            return;
        }
        if (m.find(v[i]) == m.end()) {
            m[v[i]] = new Trie();
        }
        m[v[i]]->insert(v, i + 1);
    }

    void dfs(int d) {
        for (auto& i : m) {
            for (int j = 0; j < d; j++)
                cout << "--";
            cout << i.first << '\n';
            i.second->dfs(d + 1);
        }
    }

    ~Trie() {
        for (auto& i : m) {
            delete i.second;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Trie* root = new Trie();
    cin >> n;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<string> v(k);
        for (int j = 0; j < k; j++) {
            cin >> v[j];
        }
        root->insert(v, 0);
    }

    root->dfs(0);

    delete root; 
    return 0;
}
