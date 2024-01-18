#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int* score = new int[n];
    int dec = 0;

    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }
    for (int i = n - 1; i > 0; i--) {
        while (score[i] <= score[i - 1]) {
            score[i - 1]--;
            dec++;
        }
    }
    cout << dec;
}
