#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    int n=0, k=0;

    cin >> n;
    vector<int> N;
    for (int i = 0; i < n; i++) {
        N.push_back(i + 1);
    }
    cin >> k;
    int temp = k-1;
    cout << "<";
    while(N.size()!=0){
        n--;
        if (n != 0) {
            cout << N.at(temp) << ", ";
            N.erase(N.begin() + temp);
            temp += k - 1;
            temp %= n;
        }
        else {
            cout << N.at(temp);
            N.erase(N.begin() + temp);
        }
    }
    cout << ">";
    return 0;
}
