#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        cout << num / 2 + 1 << "\n";

        vector<int> test;
        for (int j = 0; j < num; j++) {
            int temp;
            cin >> temp;
            test.push_back(temp);

            if ((j + 1) % 2 == 1) {
                sort(test.begin(), test.end());
                cout << test[j / 2] << " ";
                if ((j + 2) % 20 == 0) { cout << "\n"; }
            }
        }
        cout << "\n";
    }

    return 0;
}
