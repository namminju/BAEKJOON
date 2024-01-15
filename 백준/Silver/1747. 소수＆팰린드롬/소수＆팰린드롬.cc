#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isprime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool ispalindrome(int n) {
    int temp = n;
    int rev = 0;
    while (n > 0) {
        rev = 10 * rev + n % 10;
        n /= 10;
    }
    return temp == rev;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = n; i <= 1003001; i++) {
        if (ispalindrome(i) && isprime(i)) {
            cout << i;
            break;
        }
    }
}
