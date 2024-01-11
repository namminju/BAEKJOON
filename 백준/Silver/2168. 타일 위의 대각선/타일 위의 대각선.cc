#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
        return a;
}
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int x = 0, y = 0;
    cin >> x >> y;

    cout << x + y - gcd(x, y);


    return 0;
}
