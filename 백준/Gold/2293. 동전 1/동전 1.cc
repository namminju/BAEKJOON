#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);


    int n, sum;
    cin >> n >> sum;
    int* dp = new int[sum + 1];
    for (int i = 1; i <= sum; i++) {
        dp[i] = 0;
    }
    int value;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> value;
        for (int i = 1; i <= sum; i++)
        {
            if (i >= value)
            {
                dp[i] = dp[i] + dp[i - value];
            }
        }
    } 
    cout << dp[sum];
    delete[] dp;
    return 0;
}
