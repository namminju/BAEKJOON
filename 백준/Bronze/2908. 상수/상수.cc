#include<iostream>
#include<string>
using namespace std;
int main() {
    int a, b, a2 = 0, b2 = 0;
    cin >> a >> b;
    while (a) {
        a2 = a2 * 10 + a % 10;
        a = a / 10;
    }
    while (b) {
        b2 = b2 * 10 + b % 10;
        b = b / 10;
    }
    if (a2 > b2) {
        cout << a2;
    }
    else { cout << b2; }
    return 0;
}