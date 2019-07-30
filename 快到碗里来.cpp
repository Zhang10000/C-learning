#include<iostream>
using namespace std;
int main() {
	double s1, s2;
	while (cin >> s1 >> s2) {
		if (s1 < s2 * 6.28)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	system("pause");
	return 0;
}