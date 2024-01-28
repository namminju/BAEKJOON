#include <iostream>
#include <vector>
#include <map>
using namespace std;

int change(int a) {
    if (a == 1) {
        return 0;
    }
    else if (a == 0) {
        return 1;
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int* switches = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        cin >> switches[i];
    }

    int human;
    cin >> human;
    int sex = 0, num = 0;
    for (int i = 1; i <= human; i++) {
        cin >> sex >> num;
        if (sex == 1) {

            for (int j = 1; j * num <= n; j++) {
                switches[j * num] = change(switches[j * num]);
            }
        }
        else if (sex == 2) {
            for (int j = 0; (num - j) > 0 && (num + j) <= n; j++) {
                if (switches[num - j] == switches[num + j]) {
                    switches[num - j] = switches[num + j] = change(switches[num + j]);
                }
                else {
                    break;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << switches[i] << " ";
        if (i % 20 == 0) {
            cout << "\n";
        }
    }
    delete[] switches;
    return 0;
}
