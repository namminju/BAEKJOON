#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Person
{
    int money = 0;
    int shares_num = 0;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int money;
    Person jun, sung;
    cin >> money;
    jun.money = sung.money = money;

    int stock[14] = {};
    for (int i = 0; i < 14; i++) {
        cin >> stock[i];
        if (jun.money >= stock[i]) {
            jun.shares_num += jun.money / stock[i];
            jun.money = jun.money % stock[i];
        }
        if (i >= 3) {
            if (stock[i] > stock[i - 1] && stock[i - 1] > stock[i - 2] && stock[i - 2] > stock[i - 3]) {
                sung.money += stock[i] * sung.shares_num;
                sung.shares_num = 0;
            }
            else if (stock[i] < stock[i - 1] && stock[i - 1] < stock[i - 2] && stock[i - 2] < stock[i - 3]) {
                sung.shares_num += sung.money / stock[i];
                sung.money = sung.money % stock[i];
            }
        }
    }
    jun.money += stock[13] * jun.shares_num;
    sung.money += stock[13] * sung.shares_num;

    if (jun.money > sung.money) {
        cout << "BNP";
    }
    else if (jun.money < sung.money){
        cout << "TIMING";
    }
    else if (jun.money == sung.money) {
        cout << "SAMESAME";
    }

    //cout << "jun: " << jun.money << "\nsung: " << sung.money;
    return 0;

}
