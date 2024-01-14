#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<int>> arr;

void create(int a[], int start, int end, int index) {
    if (start > end) {
        return;
    }

    int middle = (start + end) / 2;
    arr[index].push_back(a[middle]);

    create(a, start, middle - 1, index + 1);
    create(a, middle + 1, end, index + 1);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int node_num = (int)pow(2, n) - 1;
    int* num = new int[node_num];

    for (int i = 0; i < node_num; i++) {
        int temp = 0;
        cin >> temp;
        num[i] = temp;
    }

    arr.resize(node_num);
    create(num, 0, node_num - 1, 0);

    // 출력
    for (const auto& vec : arr) {
        for (int val : vec) {
            cout << val << " ";
        }
        cout << "\n";
    }

    delete[] num;
    return 0;
}
