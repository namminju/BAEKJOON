#include <iostream>
#include <string>
#include <stack>
#include <iomanip>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    string str = "";
    stack<double> num;
    int* number_array = new int[n];
    cin >> str;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        number_array[i] = temp;
    }

    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            double temp = number_array[str[i] - 'A'];
            num.push(temp);
        }
        else {
            double o1, o2;
            if (num.size() == 0) { return 0; }
            o1 = num.top();
            num.pop();
            o2 = num.top();
            num.pop();

            switch (str[i]) {
            case '*':
                num.push(o2 * o1);
                break;
            case '+':
                num.push(o2 + o1);
                break;
            case '/':
                num.push(o2 / o1);
                break;
            case '-':
                num.push(o2 - o1);
                break;

            }
        }
    }

    double result=num.top();
    printf("%.2f\n", result);
    delete[] number_array;
    return 0;
}
