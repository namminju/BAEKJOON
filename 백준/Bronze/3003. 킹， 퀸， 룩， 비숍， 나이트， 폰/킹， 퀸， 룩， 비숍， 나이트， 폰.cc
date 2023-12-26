#include<iostream>
#include<string>
using namespace std;
int main() {
	int num[6] = {};
	int req[6] = {1, 1, 2, 2, 2, 8};
	for (int i = 0; i < 6; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 6; i++) {
		cout << req[i] - num[i] << " ";
	}
	return 0;
}