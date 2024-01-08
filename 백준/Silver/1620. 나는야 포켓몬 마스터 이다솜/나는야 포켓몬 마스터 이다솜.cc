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
    map<string, int> poketmon_name;
    map<int, string> poketmon_number;
    for (int i = 0; i < n; i++) {
        string name="";
        cin >> name;
        poketmon_name[name] = i + 1;
        poketmon_number[i + 1] = name;
    }
    for (int i = 0; i < m; i++) {
        string q;
        cin >> q;
        if (q[0] > '0' && q[0] <= '9') {
            int temp = stoi(q);
            cout << poketmon_number[temp] << "\n";
        }
        else {
            cout << poketmon_name[q] << "\n";
        }
    }
    return 0;
}
