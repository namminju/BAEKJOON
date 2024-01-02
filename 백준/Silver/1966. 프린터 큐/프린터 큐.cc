#include <iostream>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

struct Document {
    int pri = 0;
    int seq = 0;
};

bool compare(const int& d1, const int& d2) {
    return d1 > d2;  // pri가 큰 것부터 정렬
}

int main() {
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int doc = 0;
        cin >> doc;
        int que = 0;
        cin >> que;

        queue<Document> test;
        vector<int> big;

        for (int j = 0; j < doc; j++) {
            int input = 0;
            cin >> input;
            big.push_back(input);

            Document t;
            t.pri = input;
            t.seq = j;
            test.push(t);
        }

        sort(big.begin(), big.end(), compare);

        int now = 0;

        while (test.size()>0) {
            if (big[now] != test.front().pri) {
                Document in = test.front();
                test.pop();
                test.push(in);
            }
            else { 
                if (que == test.front().seq) {
                    cout << now+1 << endl;
                }
                now++; 
                test.pop();
            }
        }
    }

    return 0;
}
