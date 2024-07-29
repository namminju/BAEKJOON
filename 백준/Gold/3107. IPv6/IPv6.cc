#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string addr;
    cin >> addr;

    vector<string> parts;
    stringstream ss(addr);
    string part;


    while (getline(ss, part, ':')) {
        parts.push_back(part);
    }

    vector<string> expanded(8, "0000");
    int idx = 0;


    for (int i = 0; i < parts.size(); i++) {
        if (parts[i].empty()) {  
            idx = 8 - (parts.size() - 1 - i);
        }
        else {
            expanded[idx] = string(4 - parts[i].size(), '0') + parts[i];
            idx++;
        }
    }

    for (int i = 0; i < expanded.size(); i++) {
        if (i > 0) {
            cout << ":";
        }
        cout << expanded[i];
    }
    cout << endl;

    return 0;
}
