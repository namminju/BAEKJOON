#include<iostream>
#include<string>
using namespace std;

int main() {
	string sentence="";
	cin >> sentence;
	for (int i = 0; i < sentence.length() / 2; i++) {
		if (sentence[i] != sentence[sentence.length() - 1 - i]) {
			cout << "0";
			return 0;
		}
	}
	cout << "1";
	return 0;
}