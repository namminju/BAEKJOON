#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> honey;
    vector<int> sum;
    int result = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        honey.push_back(tmp);

        if (i == 0) {
            sum.push_back(tmp);
        }
        else {

            sum.push_back(sum[i - 1] + tmp);

        }
    }
    //벌,벌,벌통
    for (int i = 1; i < n - 1; i++) {
        int compare = sum[n - 1] - sum[0] - honey[i] + sum[n - 1] - sum[i];
        result = max(result, compare);
    }
    //벌,벌통,벌
    for (int i = 1; i < n - 1; i++) {
        int compare = sum[i] - sum[0] + sum[n - 2] - sum[i - 1];
        result = max(result, compare);
    }
    //벌통,벌,벌
    for (int i = 1; i < n - 1; i++) {
        int compare = sum[n - 2] - honey[i] + sum[i - 1];
        result = max(result, compare);
    }

    cout << result;
    return 0;
}
