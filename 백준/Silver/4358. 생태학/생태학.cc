#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int whole = 0;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    int num = 0;

    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        whole++;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isEndOfWord = true;
        current->num++;
    }

    int findWordNode(const string& word) {
        TrieNode* current = root;
        for (char c : word) {
            if (current->children.find(c) == current->children.end()) {
                return 0;
            }
            current = current->children[c];
        }
        return current->num;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Trie trie;
    set<string> trees;
    string tree;
    while (getline(cin, tree) && !tree.empty()) {
        trie.insert(tree);
        trees.insert(tree);
    }

    cout << fixed << setprecision(4);
    for (const string& t : trees) {
        double percentage = (double)trie.findWordNode(t) / whole * 100.0;
        cout << t << " " << percentage << endl;
    }

    return 0;
}
