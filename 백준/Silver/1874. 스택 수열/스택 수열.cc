#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n = 0, present = 1;
    bool possible = true;
    string result="";
    stack<int> number;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        while (present <= temp) {
            number.push(present);
            present++;
            result+='+';
        }

        if (temp == number.top()) {
            result += '-';
            number.pop();
        }
        else {
            possible = false;
            break;
        }
    }

    if (possible) {
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << "\n";
        }
     }
    else {
        cout << "NO";
    }

    return 0;
}
