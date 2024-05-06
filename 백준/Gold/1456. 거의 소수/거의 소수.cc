#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    long long result = 0;
    long long a, b;
    cin >> a >> b;

    vector<bool> prime(10000001, true);
    vector<long long> check;

    for (long long i = 2; i * i < b; i++) {
        if (prime[i]) {
            check.push_back(i);
            for (long long j = i * 2; j <= 10000000; j += i)
                prime[j] = false;
        }
    }

    for (long long num : check) {
        long long i = num;

        while (i <= b/num) {
            i *= num;
            if (i >= a) {
                result++;
            }

        }
    }

    cout << result << "\n";
    return 0;
}
