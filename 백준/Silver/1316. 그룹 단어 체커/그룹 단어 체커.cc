#include<iostream>
#include<string>
using namespace std;
bool issentence(string temp) {
	int alpha[26] = {};
	for (int i = 0; i < temp.length(); i++) {
		if (alpha[temp[i] - 'a'] == 0) { alpha[temp[i] - 'a']++; }
		else if (temp[i - 1] != temp[i]) { return false; }
	}
	return true;
}

int main() {
	
	int num = 0, result = 0;
	cin >> num;
	for (int i = 0; i < num; i++) {
		string temp = "";
		cin >> temp;
		if (issentence(temp)) {
			result++;
		}
	}
	cout << result;
	return 0;
}