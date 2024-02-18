#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

string result = "";

void Press(vector<vector<int>>& video, int n, int x, int y) {
    if (n == 1) {
        result += to_string(video[x][y]);
        return;
    }

    int now = n / 2;
    bool same = true;
    int first = video[x][y];
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (video[i][j] != first) {
                same = false;
                break;
            }
        }
        if (!same) break;
    }

    if (same) {
        result += to_string(first);
    }
    else {
        result += "(";
        Press(video, now, x, y);
        Press(video, now, x, y + now);
        Press(video, now, x + now, y);
        Press(video, now, x + now, y + now);
        result += ")";
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> video(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            video[i][j] = tmp[j] - '0';
        }
    }

    Press(video, n, 0, 0);

    cout << result;
    return 0;
}
