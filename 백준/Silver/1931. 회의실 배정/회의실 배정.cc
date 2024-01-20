#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int max_meeting = 1;

struct Meeting
{
    int start = 0; int end = 0;
};

bool compareMeetings(const Meeting& a, const Meeting& b) {
    if (a.end != b.end) {
        return a.end < b.end;
    }
    else {
        return a.start < b.start;
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<Meeting> meet;
    for (int i = 0; i < n; i++) {
        Meeting temp;
        cin >> temp.start >> temp.end;
        meet.push_back(temp);
    }
    sort(meet.begin(), meet.end(), compareMeetings);

    int time = meet[0].end;
    for (int i = 1; i < n; i++) {
        if (meet[i].start >= time) {
            time = meet[i].end;
            max_meeting++;
        }

    }



    cout << max_meeting;
    return 0;
}
