#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;
    int n, k;
    cin >> n >> k;
    vector<int> kids;
    vector<int> cost;


    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        kids.push_back(tmp);
    }
    for (int i = 0; i < n - 1; i++) {
        cost.push_back(kids[i+1]- kids[i]);
    }
    sort(cost.begin(), cost.end());

    for (int i = 0; i < n - k; i++) {
        result += cost[i];
    }

    cout << result;
    return 0;
}
