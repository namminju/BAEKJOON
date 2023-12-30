#include <iostream>
#include <string>
#include <deque>
#include <sstream>
using namespace std;

int main() {

    int n = 0;
    cin >> n;

    deque<int> stack;

    for (int i = 0; i < n; i++) {
        string temp = ""; int num = 0;
        cin >> temp;

        if (temp == "push_front") {
            cin >> num;
            stack.push_front(num);
        }else if (temp == "push_back") {
            cin >> num;
            stack.push_back(num);
        }
        else if (temp == "pop_front") {
            if (!stack.empty()) {
                cout << stack.front() << "\n";
                stack.pop_front();
            }
            else {
                cout << "-1" << "\n";
            }
        }
        else if (temp == "pop_back") {
            if (!stack.empty()) {
                cout << stack.back() << "\n";
                stack.pop_back();
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
