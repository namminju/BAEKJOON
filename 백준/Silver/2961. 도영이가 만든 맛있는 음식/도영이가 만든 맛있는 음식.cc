#include <iostream>
#include <vector>
using namespace std;

int n, so, bi, result;
class FoodIn {
public:
    int sour = 0;
    int bitter = 0;

};
void Delicious(FoodIn* tmp, int sour, int bitter, int s) {

    for (int i = s; i < n; i++) {
        so = sour * tmp[i].sour;
        bi = bitter + tmp[i].bitter;
        result = min(result, abs(so - bi));
        if (i + 1 < n) {
            Delicious(tmp, so, bi, i + 1);
        }
    }
   
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    FoodIn* in = new FoodIn[n];
    for (int i = 0; i < n; i++) {
        cin >> in[i].sour >> in[i].bitter;
    }
    result = abs(in[0].sour - in[0].bitter); 

    for (int i = 0; i < n; i++) {
        so = in[i].sour;
        bi = in[i].bitter;
        result = min(result, abs(so - bi));
        if (i + 1 < n) {
            Delicious(in, so, bi, i + 1);
        }
    }

    cout << result;
    return 0;
}
