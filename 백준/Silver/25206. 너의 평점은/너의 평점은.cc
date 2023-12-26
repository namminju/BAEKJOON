#include<iostream>
#include<string>
using namespace std;
struct grade
{
	string object="";
	double degree=0;
	string sgrade="";
};
double reverse(string sgrade) {
	if (sgrade == "A+") { return 4.5; }
	else if (sgrade == "A0") { return 4.0; }
	else if (sgrade == "B+") { return 3.5; }
	else if (sgrade == "B0") { return 3.0; }
	else if (sgrade == "C+") { return 2.5; }
	else if (sgrade == "C0") { return 2.0; }
	else if (sgrade == "D+") { return 1.5; }
	else if (sgrade == "D0") { return 1.0; }
	else if (sgrade == "F") { return 0.0; }
	else if (sgrade == "P") { return 10; }

}
int main() {
	double totalsum = 0, degreesum = 0;
	grade g[20];
	for (int i = 0; i < 20; i++) {
		cin >> g[i].object >> g[i].degree >> g[i].sgrade;
		if (reverse(g[i].sgrade) != 10) {
			totalsum += g[i].degree * reverse(g[i].sgrade);
			degreesum += g[i].degree;
		}
	}
	cout << totalsum / degreesum;
	return 0;
}