#include <iostream>
#include <vector>
using namespace std;
struct FoodIngredients
{
    int sour = 0;
    int bitter = 0;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int* DP = new int[n + 1];
    int max_sum = 0;
    int result = 0;
    for (int i = 0; i < n + 1; i++) {
        DP[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t >> p;
        if (i + t <= n) {
            for (int j = 0; j <= i; j++) {
                max_sum = max(max_sum, DP[j]);
            }
            DP[i + t] = max(DP[i + t], max_sum + p);
            result = max(result, DP[i + t]);
        }
    }

    cout << result;

    delete[] DP;
    return 0;
}
