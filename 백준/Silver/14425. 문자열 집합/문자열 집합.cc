#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    map<string, int> set;
    int result=0;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        set[temp] = 1;
    }
    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        if (set.find(temp) != set.end()) {
            result++;
        }
    }
    cout << result << "\n";
    return 0;
}
