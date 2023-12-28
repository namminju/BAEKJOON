#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int n = 0;
    int left = 0, right = 0;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        left = 0, right = 0;
        string str = "";
        getline(cin, str);
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(') { left++; }
            else if (str[j] == ')') { right++; }
            if (left < right) { cout << "NO"<< endl; break; }
            if (j== str.length()-1) { 
                if (left != right) {
                    cout << "NO" << endl;
                }
                else { cout << "YES" << endl; }
            }
        }
        
    }
    return 0;
}
