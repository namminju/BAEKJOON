#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);

    ios_base::sync_with_stdio(false);
    int n = 0;
    cin >> n;

    queue<int> stack;

    for (int i = 0; i < n; i++) {
        string temp = ""; int num = 0;
        cin >> temp;

        if (temp == "push") {
            cin >> num;
            stack.push(num);
        }
        else if (temp == "pop") {
            if (!stack.empty()) {
                cout << stack.front() << "\n";
                stack.pop();
            }
            else {
                cout << "-1" << "\n";
            }
        }
        else if (temp == "size") {
            cout << stack.size() << "\n";
        }
        else if (temp == "empty") {
            if (!stack.empty()) {
                cout << "0" << "\n";
            }
            else {
                cout << "1" << "\n";
            }
        }
        else if (temp == "front") {
            if (!stack.empty()) {
                cout << stack.front() << "\n";
            }
            else {
                cout << "-1" << "\n";
            }
        }
        else if (temp == "back") {
            if (!stack.empty()) {
                cout << stack.back() << "\n";
            }
            else {
                cout << "-1" << "\n";
            }
        }
    }

    return 0;
}
