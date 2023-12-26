#include<iostream>
#include<string>
using namespace std;
int stringtonumber(char temp){
    if (temp <= 'C') {return 2;}
    else if (temp <= 'F') { return 3; }
    else if (temp <= 'I') { return 4; }
    else if (temp <= 'L') { return 5; }
    else if (temp <= 'O') { return 6; }
    else if (temp <= 'S') { return 7; }
    else if (temp <= 'V') { return 8; }
    else if (temp <= 'Z') { return 9; }
    else { return 0; }

}
int main() {
    string number="";
    int time = 0;
    cin >> number;
    for (int i = 0; i < number.length(); i++) {
        time++;
        time+=stringtonumber(number[i]);
     }
    cout << time;
    return 0;
}