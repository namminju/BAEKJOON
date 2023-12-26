#include<iostream>
#include<string>
using namespace std;
int main() {
    int n = 0, sum = 0;
    string number="";
    cin >> n;
    cin >> number;
    for (int i = 0; i < n; i++) {
        sum+=number[i]-'0';
    }
    cout << sum;
    return 0;
}