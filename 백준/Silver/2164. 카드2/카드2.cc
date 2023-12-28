#include <iostream>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

int main() {
    int n = 0;

    cin >> n;
    queue<int> card;
    for (int i = 0; i < n; i++) {
        card.push(i + 1);
    }
    while (card.size() != 1) {
        card.pop();
        int temp = card.front();
        card.pop();
        card.push(temp);
    }
    cout << card.front();
    return 0;
}
