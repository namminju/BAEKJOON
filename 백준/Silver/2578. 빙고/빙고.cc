#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct location
{
    int x = 0;
    int y = 0;
};
struct Bingo
{
    int num = 0;
    bool called = false;
};


int BingoCount(Bingo temp[5][5]) {
    int count = 2;
    for (int i = 0; i < 5; i++) {
        bool full = true;
        for (int j = 0; j < 5; j++) {
            if (!temp[i][j].called) {
                full = false;
                break;
            }
        }
        if (full) {
            count++;
        }
        
    }
    for (int i = 0; i < 5; i++) {
        bool full = true;
        for (int j = 0; j < 5; j++) {
            if (!temp[j][i].called) {
                full = false;
                break;
            }
        }
        if (full) {
            count++;
        }
    }        
    bool full = true;
    for (int i = 0; i < 5; i++) {
        if (!temp[i][4 - i].called) {
                count--;
                break;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (!temp[i][i].called) {
            count--;
            break;
        }
    }


    return count;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Bingo game[5][5];
    map<int, location> loc;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> game[i][j].num;
            location temp;
            temp.x = i, temp.y = j;
            loc[game[i][j].num] = temp;
        }
    }
    int result = 0;
    for (int i = 0; i < 25; i++) {
        int temp;
        cin >> temp;
        game[loc[temp].x][loc[temp].y].called = true;
        if (BingoCount(game) >= 3) {
            result = i + 1;
            break;
        }
    }
    cout << result;
    return 0;
}
