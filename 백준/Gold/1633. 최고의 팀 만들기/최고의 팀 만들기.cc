#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <sstream>
using namespace std;

#define MAX 10001

int i = 0;
int white[1001], black[1001];
int DP[1001][16][16];

int MakeTeam(int idx, int w, int b) {
    if (w == 15 && b == 15) return 0;
    if (idx == i) return 0;
    if (DP[idx][w][b]) return DP[idx][w][b];
    int ans = 0;
    if (w < 15) {
        ans = MakeTeam(idx + 1, w + 1, b) + white[idx];
    }
    if (b < 15) {
        ans = max(ans, MakeTeam(idx + 1, w, b + 1) + black[idx]);
    }
    return DP[idx][w][b] = max(ans, MakeTeam(idx + 1, w, b));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 받기
    while (true) {
        string input;
        getline(cin, input);
        if (input.empty()) { break; }
        int w, b;
        stringstream ss(input);
        ss >> w >> b;
        if (w == 0 && b == 0) { break; } // 종료 조건
        white[i] = w;
        black[i++] = b;
    }

    // DP 배열 초기화
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 16; k++) {
            for (int l = 0; l < 16; l++) {
                DP[j][k][l] = 0;
            }
        }
    }

    // MakeTeam 함수 호출
    cout << MakeTeam(0, 0, 0) << endl;

    return 0;
}
