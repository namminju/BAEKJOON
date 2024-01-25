#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int* num = new int[n];
    map<int, map<int, long long int>> DP;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int j = 0; j < 21; j++) {
        DP[0][j] = 0;
    }
    DP[0][num[0]] = 1;


    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 21; j++) {
            DP[i][j] = 0;
        }
        for (int j = 0; j < 21; j++) {
            if (DP[i - 1][j]!=0) {
                if (j - num[i] >= 0) {
                    DP[i][j - num[i]]+= DP[i - 1][j] ;
                    //cout << i << "번째: " << j - num[i] << "\n";
                }
                if (j + num[i] <= 20) {
                    DP[i][j + num[i]] += DP[i - 1][j];
                    //cout << i << "번째: " << j + num[i] << "\n";
                }
            }            
        }
    }

   
    cout << DP[n - 2][num[n - 1]];

    delete[] num;
    return 0;
}
