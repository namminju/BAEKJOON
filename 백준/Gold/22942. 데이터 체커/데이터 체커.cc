#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Circle
{
public:
    int r;
    int oc;
    int num;

    Circle(int r, int oc, int num) {
        this->r = r;
        this->oc = oc;
        this->num = num;
    }

    // Compare function to sort circles based on their radii
    static bool compare(const Circle& a, const Circle& b) {
        return a.r < b.r;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool condition = true;
    int n;
    cin >> n;
    vector<Circle> circles;
    stack<Circle> can;

    for (int i = 0; i < n; i++) {
        int c, r;
        cin >> c >> r;
        circles.push_back(Circle(c - r, -1, i));
        circles.push_back(Circle(c + r, 1, i));
    }

    sort(circles.begin(), circles.end(), Circle::compare);

    for (auto& tmp : circles) {
        if (!can.empty() && can.top().num == tmp.num) {
            can.pop();
        }
        else if (!can.empty() && can.top().oc * tmp.oc < 0) {
            condition = false;
            break;
        }
        else {
            can.push(tmp);
        }
    }

    if (condition) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
    return 0;
}
