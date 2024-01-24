#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int result = 0;
    int a, b;
    cin >> a >> b;
    int *a_array = new int[a];
    int *b_array = new int[b];
    int* sum_array = new int[a+b];

    for (int i = 0; i < a; i++) {
        cin >> a_array[i];
    }
    for (int i = 0; i < b; i++) {
        cin >> b_array[i];
    }

    int a_index = 0, b_index = 0, i=0;
    while (a_index < a && b_index < b) {
        if (a_array[a_index] < b_array[b_index]) {
            sum_array[i] = a_array[a_index];
            a_index++;
        }
        else {
            sum_array[i] = b_array[b_index];
            b_index++;
        }
        i++;
    }
    if (a_index < a) {
        while (a_index < a) {
            sum_array[i] = a_array[a_index];
            a_index++;
            i++;
        }
    }
    if (b_index < b) {
        while (b_index < b) {
            sum_array[i] = b_array[b_index];
            b_index++;
            i++;
        }
    }

    for (int j = 0; j < a + b; j++) {
        cout << sum_array[j] << " ";
    }

    delete[] a_array;
    delete[] b_array;
    delete[] sum_array;
    return 0;
}
