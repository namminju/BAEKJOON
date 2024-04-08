#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> top(n);
    stack<pair<int, int>> s; 

    for (int i = 0; i < n; ++i) {
        cin >> top[i];


        while (!s.empty() && s.top().first < top[i]) {
            s.pop(); 
        }

        if (s.empty()) {
            cout << "0 ";
        }
        else {
            cout << s.top().second << " ";
        }

        s.push({ top[i], i + 1 });
    }

    return 0;
}
