#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap; 

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        }
        else {
            min_heap.push(num);
        }

        while (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        while (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }


        if (max_heap.size() > min_heap.size())
            cout << max_heap.top() << "\n";
        else
            cout << min(max_heap.top() , min_heap.top()) << "\n";
    }

    return 0;
}
