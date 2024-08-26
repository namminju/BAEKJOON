#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;

class Trie {
public:
    bool fin;
    Trie* next[10];

    Trie() : fin(false) {
        fill(next, next + 10, nullptr);
    }

    bool insert(const char* key) {
        Trie* node = this;
        while (*key) {
            int curr = *key - '0';
            if (node->next[curr] == nullptr) {
                node->next[curr] = new Trie();
            } else if (node->next[curr]->fin) {
                return false;
            }
            node = node->next[curr];
            key++;
        }
        node->fin = true;
        for (int i = 0; i < 10; i++) {
            if (node->next[i] != nullptr) {
                return false;
            }
        }
        return true;
    }

    ~Trie() {
        for (int i = 0; i < 10; i++) {
            delete next[i];
        }
    }
};

string isConsistency(int n, vector<string>& phoneNumbers) {
    Trie trie;

    // 전화번호 사전 정렬
    sort(phoneNumbers.begin(), phoneNumbers.end());

    for (int i = 0; i < n; i++) {
        if (!trie.insert(phoneNumbers[i].c_str())) {
            return "NO";
        }
    }
    return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> phoneNumbers(n);
        for (int i = 0; i < n; i++) {
            cin >> phoneNumbers[i];
        }
        cout << isConsistency(n, phoneNumbers) << "\n";
    }

    return 0;
}
