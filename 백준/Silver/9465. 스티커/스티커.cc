#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int repeat;
    cin >> repeat;

    for (int j = 0; j < repeat; j++) {
        int n;
        cin >> n;

        int** sticker = new int* [2];
        int** score = new int* [2];
        for (int i = 0; i < 2; i++) {
            sticker[i] = new int[n];
            score[i] = new int[n];
        }

        for (int i = 0; i < n; i++) {
            cin >> sticker[0][i];
        }
        for (int i = 0; i < n; i++) {
            cin >> sticker[1][i];
        }

        if (n == 1) {
            cout << max(sticker[0][0], sticker[1][0]) << "\n";
        }
        else if (n == 2) {
            int a = sticker[1][0] + sticker[0][1], b = sticker[0][0] + sticker[1][1];
            cout << max(a, b) << "\n";
        }
        else {
            score[0][0] = sticker[0][0];
            score[1][0] = sticker[1][0];
            score[0][1] = score[1][0] + sticker[0][1];
            score[1][1] = score[0][0] + sticker[1][1];
            for (int i = 2; i < n; i++) {
                score[0][i] = max(score[1][i - 1], score[1][i - 2]) + sticker[0][i];
                score[1][i] = max(score[0][i - 1], score[0][i - 2]) + sticker[1][i];
            }
            cout << max(score[0][n - 1], score[1][n - 1]) << "\n";
        }

        for (int i = 0; i < 2; i++) {
            delete[] sticker[i];
            delete[] score[i];
        }
        delete[] sticker;
        delete[] score;
    }

    return 0;
}
