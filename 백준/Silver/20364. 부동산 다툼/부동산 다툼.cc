#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
struct Node {
    int num = 0;
    bool owner = false;
};
int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    Node* ground = new Node[n];
    for (int i = 0; i < n; i++) {
        ground[i].num = i + 1;
    }
    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        int now = temp;
        stack<int> route;
        for (int j = temp; temp > 0; temp = temp / 2) {
            route.push(temp);
        }
        bool can = true;
        while (route.size() != 0) {
            int temp=route.top();
            route.pop();
            if (ground[temp - 1].owner) {
                cout << temp << "\n";
                can = false;
                break;
            }
        }
        if (can) {
            ground[now-1].owner = true;
            cout << 0 << "\n";
        }
    }
    return 0;
}
