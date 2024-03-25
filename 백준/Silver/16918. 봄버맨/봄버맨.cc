#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Coord
{
    int x; int y;
};
struct Graph
{
    char c;
    int time;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c, n;
    cin >> r >> c >> n;
    vector<vector<Graph>> temp(r + 2, vector<Graph>(c + 2));
    vector<vector<Graph>> graph(r + 2, vector<Graph>(c + 2));
    deque<Coord> cood;
    deque<Coord> pop;

    for (int i = 0; i <= c + 1; i++) {
        graph[0][i].c = '*';
        graph[r + 1][i].c = '*';
    }
    for (int j = 1; j <= r + 1; j++) {
        graph[j][0].c = '*';
        graph[j][c + 1].c = '*';
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            char tmp;

            cin >> tmp;
            graph[i][j].c = tmp;
            if (tmp == 'O') {
                graph[i][j].time = 2;
            }
            else {
                graph[i][j].time = NULL;
            }
        }
    }

    for (int t = 1; t < n; t++) {

        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                if (graph[i][j].time > 0) {
                    graph[i][j].time-=1;
                }
            }
        }

        temp = graph;
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (graph[i][j].c == 'O' && graph[i][j].time == 0) {
                        temp[i][j + 1].c = '.';
                        temp[i][j - 1].c = '.';
                        temp[i + 1][j].c = '.';
                        temp[i - 1][j].c = '.';
                        temp[i][j].c = '.';
                    }
                }
            }
            graph = temp;
         if (t % 2 == 1) {
            for (int i = 1; i <= r; i++) {
                for (int j = 1; j <= c; j++) {
                    if (graph[i][j].c == '.') {
                        graph[i][j].c = 'O';
                        graph[i][j].time = 3;
                    }
                }
            }
        }
         /*
        cout << t << "초 후: " << "\n";
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cout << graph[i][j].c << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                cout << graph[i][j].time << " ";
            }
            cout << "\n";
        }*/
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            cout << graph[i][j].c;
        }
        cout << "\n";
    }

    return 0;
}
