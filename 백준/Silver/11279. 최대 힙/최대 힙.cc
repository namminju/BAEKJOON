#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <string>

using namespace std;
vector<int> heap;
void swap(int& a, int& b) {
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void addHeap(int n) {
    heap.push_back(n);
    int now = heap.size()-1;
    for (int i = 0; i < heap.size() / 2; i++) {
        if (heap[(now - 1) / 2] < heap[now]) {
            swap(heap[(now - 1) / 2], heap[now]);
        }
        else {
            break;
        }
        now = (now - 1) / 2;
    }    
    /*
    int multi = 0;
    int p = 0;
    cout << "\n";
    for (int i = 0; i < heap.size(); i++) {
        p++;
        cout << heap[i] << "(" << i << ")";
        if ((p) == pow(2, multi)||i==0) {
            p = 0;
            cout << "\n";
            multi++;
        }
    }
    cout << "\n";
    cout << "\n";
    */
}

void removeHeap() {
    if (heap.empty()) {
        cout << 0 << "\n";
        return;
    }
    cout << heap[0] << "\n";
    heap[0] = heap.back();
    heap.pop_back();
    int now = 0;
    while (true) {
        int leftChild = now * 2 + 1;
        int rightChild = now * 2 + 2;
        int largest = now;
        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest == now) {
            break;
        }
        swap(heap[now], heap[largest]);
        now = largest;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;
        if (tmp == 0) {
            if (heap.empty()) {
                cout << 0 << "\n";
            }
            else {
                removeHeap();
            }
        }
        else {
            addHeap(tmp);
        }
    }
    return 0;
}
