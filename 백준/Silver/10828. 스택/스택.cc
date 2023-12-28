#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int empty(const vector<string>& stack) {
    return stack.empty() ? 1 : 0;
}

int main() {
    int n = 0;
    cin >> n;
    cin.ignore(); // Consume the newline character after reading n

    vector<string> stack;

    for (int i = 0; i < n; i++) {
        string str = "";
        getline(cin, str);
        stringstream split(str);
        string temp;
        getline(split, temp, ' ');

        if (temp == "push") {
            getline(split, temp, ' ');
            stack.push_back(temp);
        }
        else if (temp == "pop") {
            if (empty(stack) == 0) {
                cout << stack.back() << endl;
                stack.pop_back();
            }
            else {
                cout << "-1" << endl;
            }
        }
        else if (temp == "size") {
            cout << stack.size() << endl;
        }
        else if (temp == "empty") {
            cout << empty(stack) << endl;
        }
        else if (temp == "top") {
            if (empty(stack) == 0) {
                cout << stack.back() << endl;
            }
            else {
                cout << "-1" << endl;
            }
        }
    }

    return 0;
}
