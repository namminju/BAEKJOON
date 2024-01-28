#include <iostream>
#include <list>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    map<string, int> extension;
    list<string> extension_name;
    for (int i = 0; i < n; i++) {
        string file, temp="";
        cin >> file;
        size_t pos = file.find('.');
        file = file.substr(pos + 1, file.size());
        if (!extension[file]) {
            extension[file] = 1;
            extension_name.push_back(file);
        }
        else {
            extension[file]++;
        }
        //cout << file << "\n";
    }
    extension_name.sort();
    for (auto temp : extension_name) {
        cout << temp << " " << extension[temp] << "\n";
    }
}
